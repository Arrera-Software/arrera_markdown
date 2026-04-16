#include "markdowneditor.h"
#include <QRegularExpression>
#include <QTextDocument>

namespace {
bool isBlockLine(const QString &line)
{
    const QString trimmed = line.trimmed();
    if (trimmed.isEmpty()) {
        return true;
    }

    static const QRegularExpression blockPattern(
        "^(#{1,6}\\s|[-*+]\\s|\\d+\\.\\s|>\\s|```|~~~|\\||---+$|___+$|\\*\\*\\*+$)");

    return blockPattern.match(trimmed).hasMatch();
}
}

MarkdownEditor::MarkdownEditor(QWidget *parent)
    : QPlainTextEdit(parent)
{
    highlighter = new MarkdownHighlighter(this->document());
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

QString MarkdownEditor::getHtmlContent() const
{
    QString normalizedMarkdown = toPlainText();

    // Accepte les titres "#Titre" comme le highlighter, en les normalisant en "# Titre".
    normalizedMarkdown.replace(
        QRegularExpression("^(#{1,6})([^#\\s].*)$", QRegularExpression::MultilineOption),
        "\\1 \\2");

    // Convertit la syntaxe custom ++texte++ en HTML souligné.
    normalizedMarkdown.replace(
        QRegularExpression("\\+\\+([^\\n]+?)\\+\\+"),
        "<u>\\1</u>");

    // Préserve les retours à la ligne simples dans les paragraphes.
    const QStringList lines = normalizedMarkdown.split('\n');
    QStringList adjustedLines;
    adjustedLines.reserve(lines.size());

    for (int i = 0; i < lines.size(); ++i) {
        QString line = lines[i];

        if (i + 1 < lines.size()) {
            const QString nextLine = lines[i + 1];
            if (!line.trimmed().isEmpty() &&
                !nextLine.trimmed().isEmpty() &&
                !isBlockLine(line) &&
                !isBlockLine(nextLine)) {
                line += "  ";
            }
        }

        adjustedLines.append(line);
    }

    normalizedMarkdown = adjustedLines.join('\n');

    QTextDocument doc;
    doc.setMarkdown(normalizedMarkdown);

    return doc.toHtml();
}
