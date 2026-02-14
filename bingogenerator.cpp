#include "bingogenerator.h"

#include <algorithm>

BingoGenerator::BingoGenerator( QObject* parent )
    : QObject( parent )
    , m_currentIndex( 0 )
    , m_targetCount( 0 ) {

    std::random_device rd;
    m_rng = std::mt19937( rd() );

    m_allNames.push_back( "Aliança" );
    m_allNames.push_back( "Paixão" );
    m_allNames.push_back( "Cumplicidade" );
    m_allNames.push_back( "Parceria" );
    m_allNames.push_back( "Respeito" );
    m_allNames.push_back( "Doação" );
    m_allNames.push_back( "Fidelidade" );
    m_allNames.push_back( "Companheirismo" );
    m_allNames.push_back( "Harmonia" );
    m_allNames.push_back( "Romance" );
    m_allNames.push_back( "Ternura" );
    m_allNames.push_back( "Dedicação" );
    m_allNames.push_back( "﻿﻿﻿﻿Brilho" );
    m_allNames.push_back( "﻿﻿﻿﻿Luz" );
    m_allNames.push_back( "﻿﻿﻿﻿Aurora" );
    m_allNames.push_back( "﻿﻿﻿﻿Esplendor" );
    m_allNames.push_back( "﻿﻿﻿﻿Aurora" );
    m_allNames.push_back( "﻿﻿﻿﻿Fulgor" );
    m_allNames.push_back( "﻿﻿﻿﻿Resplendor" );
    m_allNames.push_back( "﻿﻿﻿﻿Claridade" );
    m_allNames.push_back( "﻿﻿﻿﻿Aurora" );
    m_allNames.push_back( "﻿﻿﻿﻿Cintilação" );
    m_allNames.push_back( "﻿﻿﻿﻿Brilhante" );
    m_allNames.push_back( "﻿﻿﻿﻿Aurífero" );
    m_allNames.push_back( "﻿﻿﻿﻿Terra" );
    m_allNames.push_back( "﻿﻿﻿﻿Semente" );
    m_allNames.push_back( "﻿﻿﻿﻿Colheita" );
    m_allNames.push_back( "﻿﻿﻿﻿Plantio" );
    m_allNames.push_back( "﻿﻿﻿﻿Roça" );
    m_allNames.push_back( "﻿﻿﻿﻿Arado" );
    m_allNames.push_back( "﻿﻿﻿﻿Enxada" );
    m_allNames.push_back( "﻿﻿﻿﻿Cercado" );
    m_allNames.push_back( "﻿﻿﻿﻿Celeiro" );
    m_allNames.push_back( "﻿﻿﻿﻿Lavoura" );
    m_allNames.push_back( "﻿﻿﻿﻿Seara" );
    m_allNames.push_back( "﻿﻿﻿﻿Sulco" );
    m_allNames.push_back( "﻿﻿﻿﻿Raiz" );
    m_allNames.push_back( "﻿﻿﻿﻿Fruto" );
    m_allNames.push_back( "﻿﻿﻿﻿Geração" );
    m_allNames.push_back( "﻿﻿﻿﻿Herança" );
    m_allNames.push_back( "﻿﻿﻿﻿Tradição" );
    m_allNames.push_back( "﻿﻿﻿﻿Descendência" );
    m_allNames.push_back( "﻿﻿﻿﻿Linhagem" );
    m_allNames.push_back( "﻿﻿﻿﻿Parentesco" );
    m_allNames.push_back( "﻿﻿﻿﻿Genealogia" );
    m_allNames.push_back( "﻿﻿﻿﻿Prole" );
    m_allNames.push_back( "﻿﻿﻿﻿Sucessão" );
    m_allNames.push_back( "﻿﻿﻿﻿Delicadeza" );
    m_allNames.push_back( "Eternidade" );
    m_allNames.push_back( "Permanência" );
    m_allNames.push_back( "Duração" );
    m_allNames.push_back( "Continuação" );
    m_allNames.push_back( "Perenidade" );
    m_allNames.push_back( "Memória" );
    m_allNames.push_back( "Saudade" );
    m_allNames.push_back( "Recordação" );
    m_allNames.push_back( "Trajetória" );
    m_allNames.push_back( "Jornada" );
    m_allNames.push_back( "Caminhada" );
    m_allNames.push_back( "Amor" );
    m_allNames.push_back( "Allan" );
    m_allNames.push_back( "Filhos" );
    m_allNames.push_back( "Lua de Mel" );
    m_allNames.push_back( "Myllene" );
    m_allNames.push_back( "Aliança" );
    m_allNames.push_back( "Bençãos" );
    m_allNames.push_back( "Futuro" );
    m_allNames.push_back( "Netos" );
    m_allNames.push_back( "Romance" );
    m_allNames.push_back( "Adélia" );
    m_allNames.push_back( "Casa" );
    m_allNames.push_back( "Maria de Fátima" );
    m_allNames.push_back( "Paciência" );
    m_allNames.push_back( "Adriana" );
    m_allNames.push_back( "Casamento" );
    m_allNames.push_back( "Guilherme" );
    m_allNames.push_back( "Maria Clara" );
    m_allNames.push_back( "Paulo" );
    m_allNames.push_back( "Andréia" );
    m_allNames.push_back( "50 Anos" );
    m_allNames.push_back( "José Roberto" );
    m_allNames.push_back( "Maria Alice" );
    m_allNames.push_back( "Vida" );
    m_allNames.push_back( "Laço" );
    m_allNames.push_back( "﻿﻿﻿Farol" );
    m_allNames.push_back( "﻿﻿﻿Âncora" );
    m_allNames.push_back( "﻿﻿﻿﻿Horta" );
    m_allNames.push_back( "﻿﻿﻿﻿Rancho" );
    m_allNames.push_back( "﻿﻿﻿Aconchego" );
    m_allNames.push_back( "Família" );
    m_allNames.push_back( "Legado" );
    m_allNames.push_back( "Doce" );
    m_allNames.push_back( "Afeto" );
    m_allNames.push_back( "Mel" );
    m_allNames.push_back( "Açúcar" );
    m_allNames.push_back( "Querência" );
    m_allNames.push_back( "Carinho" );
    m_allNames.push_back( "Afago" );
    m_allNames.push_back( "Cuidado" );
    m_allNames.push_back( "﻿﻿﻿﻿Fartura" );
    m_allNames.push_back( "Doçura" );
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
