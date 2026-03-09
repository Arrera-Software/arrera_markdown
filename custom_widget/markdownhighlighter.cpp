#include "markdownhighlighter.h"

MarkdownHighlighter::MarkdownHighlighter(QTextDocument *parent) :
    QSyntaxHighlighter(parent)
{
    setupRules();
}

void MarkdownHighlighter::setupRules() {
    HighlightingRule rule;
    rules.clear();

    // Format pour rendre les balises invisibles
    QTextCharFormat transparentFormat;
    transparentFormat.setForeground(Qt::transparent);
    transparentFormat.setFontPointSize(1);
    transparentFormat.setFontStretch(1);

    QTextCharFormat titleFormat;
    titleFormat.setFontWeight(QFont::Bold);

    titleFormat.setFontPointSize(30);
    // Capture le '#' (groupe 1) et le reste (groupe 2)
    rule.pattern = QRegularExpression("^(#)([^#].*)");
    rule.capturingGroupFormats.clear();
    rule.capturingGroupFormats.insert(1, transparentFormat);
    rule.capturingGroupFormats.insert(2, titleFormat);
    rules.append(rule);


    titleFormat.setFontPointSize(25);
    rule.pattern = QRegularExpression("^(##)([^#].*)");
    rule.capturingGroupFormats.clear();
    rule.capturingGroupFormats.insert(1, transparentFormat);
    rule.capturingGroupFormats.insert(2, titleFormat);
    rules.append(rule);

    titleFormat.setFontPointSize(20);
    rule.pattern = QRegularExpression("^(###)([^#].*)");
    rule.capturingGroupFormats.clear();
    rule.capturingGroupFormats.insert(1, transparentFormat);
    rule.capturingGroupFormats.insert(2, titleFormat);
    rules.append(rule);

    QTextCharFormat boldFormat;
    boldFormat.setFontWeight(QFont::Bold);
    // Capture ** (1), contenu (2), ** (3). Utilisation de .*? pour être non-gourmand
    rule.pattern = QRegularExpression("(\\*\\*)(.*?)(\\*\\*)");
    rule.capturingGroupFormats.clear();
    rule.capturingGroupFormats.insert(1, transparentFormat);
    rule.capturingGroupFormats.insert(2, boldFormat);
    rule.capturingGroupFormats.insert(3, transparentFormat);
    rules.append(rule);

    QTextCharFormat italicFormat;
    italicFormat.setFontItalic(true);
    rule.pattern = QRegularExpression("(_)([^_]+)(_)");
    rule.capturingGroupFormats.clear();
    rule.capturingGroupFormats.insert(1, transparentFormat);
    rule.capturingGroupFormats.insert(2, italicFormat);
    rule.capturingGroupFormats.insert(3, transparentFormat);
    rules.append(rule);

    QTextCharFormat codeFormat;
    codeFormat.setFontFixedPitch(true);
    codeFormat.setBackground(QColor("#f0f0f0"));
    rule.pattern = QRegularExpression("(`)(.*?)(`)");
    rule.capturingGroupFormats.clear();
    rule.capturingGroupFormats.insert(1, transparentFormat);
    rule.capturingGroupFormats.insert(2, codeFormat);
    rule.capturingGroupFormats.insert(3, transparentFormat);
    rules.append(rule);

    QTextCharFormat tableFormat;
    tableFormat.setForeground(Qt::darkGray);
    tableFormat.setFontWeight(QFont::Bold);
    rule.pattern = QRegularExpression("\\|");
    rule.format = tableFormat;
    rule.capturingGroupFormats.clear();
    rules.append(rule);

    QTextCharFormat headerFormat;
    headerFormat.setForeground(Qt::darkMagenta);
    headerFormat.setFontWeight(QFont::Bold);
    rule.pattern = QRegularExpression("^\\s*\\|?[\\s\\-:]+\\|[\\s\\-:\\|]*$");
    rule.format = tableFormat;
    rule.capturingGroupFormats.clear();
    rules.append(rule);

    rule.pattern = QRegularExpression("^\\|.*\\|$");
    rule.format = headerFormat;
    rule.capturingGroupFormats.clear();
    rules.append(rule);

    QTextCharFormat lineFormat;
    lineFormat.setForeground(Qt::gray);
    lineFormat.setFontWeight(QFont::Bold);
    rule.pattern = QRegularExpression("^(\\s*[-*_\\s]){3,}\\s*$");
    rule.format = lineFormat;
    rule.capturingGroupFormats.clear();
    rules.append(rule);

    QTextCharFormat linkFormat;
    linkFormat.setForeground(Qt::blue);
    linkFormat.setFontUnderline(true);

    QTextCharFormat imageFormat;
    imageFormat.setForeground(QColor("#228B22"));
    imageFormat.setFontWeight(QFont::Bold);

    QTextCharFormat bulletFormat;
    bulletFormat.setFontWeight(QFont::Bold);
    rule.pattern = QRegularExpression("^(?:[-*+])\\s");
    rule.capturingGroupFormats.clear();
    rule.capturingGroupFormats.insert(0, bulletFormat); // On formate toute la correspondance
    rules.append(rule);

    QTextCharFormat numberFormat;
    numberFormat.setFontWeight(QFont::Bold);
    rule.pattern = QRegularExpression("^(\\d+)(\\.\\s)");
    rule.capturingGroupFormats.clear();
    rule.capturingGroupFormats.insert(0, numberFormat);
    rules.append(rule);

    QTextCharFormat underlineFormat;
    underlineFormat.setFontUnderline(true);
    rule.pattern = QRegularExpression("(\\+\\+)(.*?)(\\+\\+)");
    rule.capturingGroupFormats.clear();
    rule.capturingGroupFormats.insert(1, transparentFormat);
    rule.capturingGroupFormats.insert(2, underlineFormat);
    rule.capturingGroupFormats.insert(3, transparentFormat);
    rules.append(rule);
}

void MarkdownHighlighter::highlightBlock(const QString &text) {
    for (const HighlightingRule &rule : qAsConst(rules)) {
        QRegularExpressionMatchIterator it = rule.pattern.globalMatch(text);
        while (it.hasNext()) {
            QRegularExpressionMatch match = it.next();
            
            if (rule.capturingGroupFormats.isEmpty()) {
                setFormat(match.capturedStart(), match.capturedLength(), rule.format);
            } else {
                // Appliquer les formats spécifiques aux groupes de capture
                QMapIterator<int, QTextCharFormat> i(rule.capturingGroupFormats);
                while (i.hasNext()) {
                    i.next();
                    int groupIndex = i.key();
                    if (match.capturedLength(groupIndex) > 0) {
                        setFormat(match.capturedStart(groupIndex), match.capturedLength(groupIndex), i.value());
                    }
                }
            }
        }
    }
}
