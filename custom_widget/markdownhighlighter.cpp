#include "markdownhighlighter.h"

MarkdownHighlighter::MarkdownHighlighter(QTextDocument *parent) :
    QSyntaxHighlighter(parent)
{
    setupRules();
}

void MarkdownHighlighter::setupRules() {
    HighlightingRule rule;


    QTextCharFormat titleFormat;
    titleFormat.setFontWeight(QFont::Bold);

    titleFormat.setFontPointSize(30);
    rule.pattern = QRegularExpression("^#[^#].*");
    rule.format = titleFormat;
    rules.append(rule);


    titleFormat.setFontPointSize(25);
    rule.pattern = QRegularExpression("^##[^#].*");
    rule.format = titleFormat;
    rules.append(rule);

    titleFormat.setFontPointSize(20);
    rule.pattern = QRegularExpression("^###[^#].*");
    rule.format = titleFormat;
    rules.append(rule);

    QTextCharFormat boldFormat;
    boldFormat.setFontWeight(QFont::Bold);
    rule.pattern = QRegularExpression("\\*\\*.*\\*\\*");
    rule.format = boldFormat;
    rules.append(rule);

    QTextCharFormat italicFormat;
    italicFormat.setFontItalic(true);
    rule.pattern = QRegularExpression("_[^_]+_");
    rule.format = italicFormat;
    rules.append(rule);

    QTextCharFormat codeFormat;
    codeFormat.setFontFixedPitch(true);
    codeFormat.setBackground(QColor("#f0f0f0"));
    rule.pattern = QRegularExpression("`.*`");
    rule.format = codeFormat;
    rules.append(rule);

    QTextCharFormat tableFormat;
    tableFormat.setForeground(Qt::darkGray);
    tableFormat.setFontWeight(QFont::Bold);
    rule.pattern = QRegularExpression("\\|");
    rule.format = tableFormat;
    rules.append(rule);

    QTextCharFormat headerFormat;
    headerFormat.setForeground(Qt::darkMagenta);
    headerFormat.setFontWeight(QFont::Bold);
    rule.pattern = QRegularExpression("^\\s*\\|?[\\s\\-:]+\\|[\\s\\-:\\|]*$");
    rule.format = tableFormat;
    rules.append(rule);

    rule.pattern = QRegularExpression("^\\|.*\\|$");
    rule.format = headerFormat;
    rules.append(rule);

    QTextCharFormat lineFormat;
    lineFormat.setForeground(Qt::gray);
    lineFormat.setFontWeight(QFont::Bold);
    rule.pattern = QRegularExpression("^(\\s*[-*_\\s]){3,}\\s*$");
    rule.format = lineFormat;
    rules.append(rule);

    QTextCharFormat linkFormat;
    linkFormat.setForeground(Qt::blue);
    linkFormat.setFontUnderline(true);

    QTextCharFormat imageFormat;
    imageFormat.setForeground(QColor("#228B22"));
    imageFormat.setFontWeight(QFont::Bold);
}

void MarkdownHighlighter::highlightBlock(const QString &text) {
    for (const HighlightingRule &rule : qAsConst(rules)) {
        QRegularExpressionMatchIterator it = rule.pattern.globalMatch(text);
        while (it.hasNext()) {
            QRegularExpressionMatch match = it.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
}
