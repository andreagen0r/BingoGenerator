#pragma once

#include <QDebug>
#include <QObject>
#include <QString>
#include <QQmlEngine>

#include <random>
#include <vector>

class BingoGenerator : public QObject {

    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

    Q_PROPERTY( QStringList currentWords READ currentWords NOTIFY currentWordsChanged )
    Q_PROPERTY( int currentCardIndex READ currentCardIndex NOTIFY currentCardIndexChanged )

public:
    explicit BingoGenerator( QObject* parent = nullptr );

    Q_INVOKABLE void startGeneration( int numberOfCards );

    Q_INVOKABLE void reportImageSaved();

    QStringList currentWords() const;
    int currentCardIndex() const;

signals:
    void currentWordsChanged();
    void currentCardIndexChanged();
    void generationFinished();

private:
    void prepareNextCard();

    std::vector<QString> m_allNames;
    QStringList m_currentWords;
    int m_currentIndex;
    int m_targetCount;
    std::mt19937 m_rng;
};
