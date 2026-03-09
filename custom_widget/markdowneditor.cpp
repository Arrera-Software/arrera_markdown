#include "markdowneditor.h"

MarkdownEditor::MarkdownEditor(QWidget *parent)
    : QPlainTextEdit(parent)
{
    highlighter = new MarkdownHighlighter(this->document());

    // Optionnel : une police monospace pour l'aspect "code"
    QFont font("Cascadia Code", 10);
    font.setStyleHint(QFont::Monospace);
    this->setFont(font);
}
