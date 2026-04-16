#ifndef MARKDOWNEDITOR_H
#define MARKDOWNEDITOR_H

#include <QPlainTextEdit>
#include "custom_widget/markdownhighlighter.h"

class MarkdownEditor : public QPlainTextEdit
{
public:
    explicit MarkdownEditor(QWidget *parent = nullptr);
    QString getHtmlContent() const;
private :
    MarkdownHighlighter *highlighter;
};

#endif // MARKDOWNEDITOR_H
