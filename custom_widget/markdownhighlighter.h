#ifndef MARKDOWNHIGHLIGHTER_H
#define MARKDOWNHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QRegularExpression>
#include <QMap>

class MarkdownHighlighter : public QSyntaxHighlighter
{
public:
    MarkdownHighlighter(QTextDocument *parent = nullptr);
private:
    struct HighlightingRule {
        QRegularExpression pattern;
        QTextCharFormat format;
        QMap<int, QTextCharFormat> capturingGroupFormats;
    };
    QVector<HighlightingRule> rules;
    void setupRules();
protected:
    void highlightBlock(const QString &text) override;
};

#endif // MARKDOWNHIGHLIGHTER_H
