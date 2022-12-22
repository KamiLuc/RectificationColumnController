#ifndef QUEUEABLEEDITOR_H
#define QUEUEABLEEDITOR_H

class QueueableEditor {
protected:
    bool done;
    QueueableEditor* nextEditor;

public:
    QueueableEditor() : done(false), nextEditor(nullptr) {}
    bool isDone() const {return this->done;}
    void setNextEditor(QueueableEditor* nextEditor) {this->nextEditor = nextEditor;}
    QueueableEditor* getNextEditor() {return this->nextEditor;}
    virtual void editSetting() = 0;
    virtual void onEnter() = 0;
    virtual ~QueueableEditor() = default;
};

#endif