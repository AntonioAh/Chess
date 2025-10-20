
cmake_minimum_required(VERSION 3.10)
project(progettoScacchi VERSION 1.0)

# Imposta lo standard C++ desiderato (es. C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Definisce le directory per sorgenti e header per renderle riutilizzabili e chiare
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(HEADER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/header")

# Aggiunge il file eseguibile
add_executable(scacchi
    main.cpp
    ${SOURCE_DIR}/position.cpp
    ${SOURCE_DIR}/piece.cpp
    
    ${SOURCE_DIR}/chessboard.cpp
    ${SOURCE_DIR}/pieces/king.cpp
    ${SOURCE_DIR}/pieces/queen.cpp
    ${SOURCE_DIR}/pieces/knight.cpp
    ${SOURCE_DIR}/pieces/bishop.cpp
    ${SOURCE_DIR}/pieces/rook.cpp
    ${SOURCE_DIR}/pieces/pawn.cpp
    
    # Aggiunge qui il file sorgente addizionale se esiste (es. src/graph.cpp)
    # Esempio:
)

target_include_directories(scacchi PRIVATE 
    ${HEADER_DIR}
)
