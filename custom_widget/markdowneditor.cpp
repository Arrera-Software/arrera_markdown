#include "markdowneditor.h"

MarkdownEditor::MarkdownEditor(QWidget *parent)
    : QPlainTextEdit(parent)
{
    highlighter = new MarkdownHighlighter(this->document());
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
