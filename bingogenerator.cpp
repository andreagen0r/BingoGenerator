#include "bingogenerator.h"

#include <algorithm>
#include <QSet>

BingoGenerator::BingoGenerator( QObject* parent )
    : QObject( parent )
    , m_currentIndex( 0 )
    , m_targetCount( 0 ) {

    std::random_device rd;
    m_rng = std::mt19937( rd() );

    QSet<QString> uniqueSet;


    uniqueSet.insert( "Aliança" );
    uniqueSet.insert( "Paixão" );
    uniqueSet.insert( "Cumplicidade" );
    uniqueSet.insert( "Parceria" );
    uniqueSet.insert( "Respeito" );
    uniqueSet.insert( "Doação" );
    uniqueSet.insert( "Fidelidade" );
    uniqueSet.insert( "Companheirismo" );
    uniqueSet.insert( "Harmonia" );
    uniqueSet.insert( "Romance" );
    uniqueSet.insert( "Ternura" );
    uniqueSet.insert( "Dedicação" );
    uniqueSet.insert( "﻿﻿﻿﻿Brilho" );
    uniqueSet.insert( "﻿﻿﻿﻿Luz" );
    uniqueSet.insert( "﻿﻿﻿﻿Aurora" );
    uniqueSet.insert( "﻿﻿﻿﻿Esplendor" );
    uniqueSet.insert( "﻿﻿﻿﻿Aurora" );
    uniqueSet.insert( "﻿﻿﻿﻿Fulgor" );
    uniqueSet.insert( "﻿﻿﻿﻿Resplendor" );
    uniqueSet.insert( "﻿﻿﻿﻿Claridade" );
    uniqueSet.insert( "﻿﻿﻿﻿Aurora" );
    uniqueSet.insert( "﻿﻿﻿﻿Cintilação" );
    uniqueSet.insert( "﻿﻿﻿﻿Brilhante" );
    uniqueSet.insert( "﻿﻿﻿﻿Aurífero" );
    uniqueSet.insert( "﻿﻿﻿﻿Terra" );
    uniqueSet.insert( "﻿﻿﻿﻿Semente" );
    uniqueSet.insert( "﻿﻿﻿﻿Colheita" );
    uniqueSet.insert( "﻿﻿﻿﻿Plantio" );
    uniqueSet.insert( "﻿﻿﻿﻿Roça" );
    uniqueSet.insert( "﻿﻿﻿﻿Arado" );
    uniqueSet.insert( "﻿﻿﻿﻿Enxada" );
    uniqueSet.insert( "﻿﻿﻿﻿Cercado" );
    uniqueSet.insert( "﻿﻿﻿﻿Celeiro" );
    uniqueSet.insert( "﻿﻿﻿﻿Lavoura" );
    uniqueSet.insert( "﻿﻿﻿﻿Seara" );
    uniqueSet.insert( "﻿﻿﻿﻿Sulco" );
    uniqueSet.insert( "﻿﻿﻿﻿Raiz" );
    uniqueSet.insert( "﻿﻿﻿﻿Fruto" );
    uniqueSet.insert( "﻿﻿﻿﻿Geração" );
    uniqueSet.insert( "﻿﻿﻿﻿Herança" );
    uniqueSet.insert( "﻿﻿﻿﻿Tradição" );
    uniqueSet.insert( "﻿﻿﻿﻿Descendência" );
    uniqueSet.insert( "﻿﻿﻿﻿Linhagem" );
    uniqueSet.insert( "﻿﻿﻿﻿Parentesco" );
    uniqueSet.insert( "﻿﻿﻿﻿Genealogia" );
    uniqueSet.insert( "﻿﻿﻿﻿Prole" );
    uniqueSet.insert( "﻿﻿﻿﻿Sucessão" );
    uniqueSet.insert( "﻿﻿﻿﻿Delicadeza" );
    uniqueSet.insert( "Eternidade" );
    uniqueSet.insert( "Permanência" );
    uniqueSet.insert( "Duração" );
    uniqueSet.insert( "Continuação" );
    uniqueSet.insert( "Perenidade" );
    uniqueSet.insert( "Memória" );
    uniqueSet.insert( "Saudade" );
    uniqueSet.insert( "Recordação" );
    uniqueSet.insert( "Trajetória" );
    uniqueSet.insert( "Jornada" );
    uniqueSet.insert( "Caminhada" );
    uniqueSet.insert( "Amor" );
    uniqueSet.insert( "Allan" );
    uniqueSet.insert( "Filhos" );
    uniqueSet.insert( "Lua de Mel" );
    uniqueSet.insert( "Myllene" );
    uniqueSet.insert( "Lareira" );
    uniqueSet.insert( "Bençãos" );
    uniqueSet.insert( "Futuro" );
    uniqueSet.insert( "Netos" );
    uniqueSet.insert( "Romance" );
    uniqueSet.insert( "Adélia" );
    uniqueSet.insert( "Casa" );
    uniqueSet.insert( "Maria de Fátima" );
    uniqueSet.insert( "Paciência" );
    uniqueSet.insert( "Adriana" );
    uniqueSet.insert( "Casamento" );
    uniqueSet.insert( "Guilherme" );
    uniqueSet.insert( "Maria Clara" );
    uniqueSet.insert( "Paulo" );
    uniqueSet.insert( "Andréia" );
    uniqueSet.insert( "50 Anos" );
    uniqueSet.insert( "José Roberto" );
    uniqueSet.insert( "Maria Alice" );
    uniqueSet.insert( "Vida" );
    uniqueSet.insert( "Laço" );
    uniqueSet.insert( "﻿﻿﻿Farol" );
    uniqueSet.insert( "﻿﻿﻿Âncora" );
    uniqueSet.insert( "﻿﻿﻿﻿Horta" );
    uniqueSet.insert( "﻿﻿﻿﻿Rancho" );
    uniqueSet.insert( "﻿﻿﻿Aconchego" );
    uniqueSet.insert( "Família" );
    uniqueSet.insert( "Legado" );
    uniqueSet.insert( "Doce" );
    uniqueSet.insert( "Afeto" );
    uniqueSet.insert( "Mel" );
    uniqueSet.insert( "Açúcar" );
    uniqueSet.insert( "Querência" );
    uniqueSet.insert( "Carinho" );
    uniqueSet.insert( "Afago" );
    uniqueSet.insert( "Cuidado" );
    uniqueSet.insert( "﻿﻿﻿﻿Fartura" );
    uniqueSet.insert( "Doçura" );

    m_allNames.assign( uniqueSet.cbegin(), uniqueSet.cend() );
}

void BingoGenerator::startGeneration( int numberOfCards ) {
    m_targetCount = numberOfCards;
    m_currentIndex = 0;
    prepareNextCard();
}

void BingoGenerator::prepareNextCard() {

    if ( m_currentIndex >= m_targetCount ) {
        emit generationFinished();
        return;
    }

    if ( m_allNames.size() < 24 ) {
        qWarning() << "Impossível gerar cartela. Nomes insuficientes.";
        return;
    }

    std::shuffle( m_allNames.begin(), m_allNames.end(), m_rng );

    m_currentWords.clear();

    for ( int i = 0; i < 24 && i < m_allNames.size(); ++i ) {
        m_currentWords.append( m_allNames[i] );
    }

    emit currentCardIndexChanged();
    emit currentWordsChanged();
}

void BingoGenerator::reportImageSaved() {
    qDebug() << "Cartela" << m_currentIndex << "salva.";
    m_currentIndex++;
    prepareNextCard(); // Gera a próxima cartela
}

QStringList BingoGenerator::currentWords() const {
    return m_currentWords;
}
int BingoGenerator::currentCardIndex() const {
    return m_currentIndex;
}
