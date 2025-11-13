"""Módulo de encriptado y desencriptado usando el cifrado de Vigenère."""

import numpy as np

# Construir alfabeto
ALFABETO = [chr(i) for i in range(ord('a'), ord('z') + 1)] # Minúsculas
for i in range(ord('A'), ord('Z') + 1): # Mayúsculas
    ALFABETO.append(chr(i))
# Algunos caracteres especiales
ALFABETO.append(",")
ALFABETO.append(".")

# Construir matriz de Vigenère
MATRIZ_VIGENERE = np.array([ALFABETO[i:] + ALFABETO[:i] for i in range(len(ALFABETO))])

def encriptar_con_vigenere(frase: str, clave: str) -> str:
    """Encripta una frase usando el cifrado de Vigenère con la clave dada.
    
    Args:
        frase (str): La frase a encriptar.
        clave (str): La clave para el cifrado.
    
    Returns:
        str: La frase encriptada.
    """
    frase_encriptada = []
    i = 0
    for char in frase:
        if char in ALFABETO:
            fila = ALFABETO.index(char)
            columna = ALFABETO.index(clave[i % len(clave)])
            frase_encriptada.append(MATRIZ_VIGENERE[fila][columna])
            i += 1
        else:
            frase_encriptada.append(char)  # Caracteres no en el alfabeto se mantienen igual

    return ''.join(frase_encriptada)