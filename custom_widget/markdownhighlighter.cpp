#include "markdownhighlighter.h"

MarkdownHighlighter::MarkdownHighlighter(QTextDocument *parent) :
    QSyntaxHighlighter(parent)
{
    setupRules();
}

void MarkdownHighlighter::setupRules() {
    HighlightingRule rule;

    // Titres (ex: # Titre)
    QTextCharFormat titleFormat;
    titleFormat.setFontWeight(QFont::Bold);
    titleFormat.setForeground(Qt::blue);
    rule.pattern = QRegularExpression("^#.*");
    rule.format = titleFormat;
    rules.append(rule);

    // Gras (ex: **gras**)
    QTextCharFormat boldFormat;
    boldFormat.setFontWeight(QFont::Bold);
    rule.pattern = QRegularExpression("\\*\\*.*\\*\\*");
    rule.format = boldFormat;
    rules.append(rule);

    // Code (ex: `code`)
    QTextCharFormat codeFormat;
    codeFormat.setFontFixedPitch(true);
    //codeFormat.setBackground(Qt::grey);
    rule.pattern = QRegularExpression("`.*`");
    rule.format = codeFormat;
    rules.append(rule);
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
