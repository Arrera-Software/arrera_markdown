#ifndef MARKDOWNHIGHLIGHTER_H
#define MARKDOWNHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QRegularExpression>

class MarkdownHighlighter : public QSyntaxHighlighter
{
public:
    MarkdownHighlighter(QTextDocument *parent = nullptr);
private:
    struct HighlightingRule {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> rules;
    void setupRules();
protected:
    void highlightBlock(const QString &text) override;
};

#endif // MARKDOWNHIGHLIGHTER_H
