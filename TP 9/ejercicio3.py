from vigenere import encriptar_con_vigenere
from numpy import array

FRASE = "El cifrado Cesar, es una de las tecnicas mas simples; consiste en reemplazar cada letra por otra que se encuentra un numero fijo de posiciones mas adelante."
CLAVE = "Ventilado"
CUADRADO_DE_POLIBIO = array([
    'a','b','c','d','e','f','g','h',
    'i','j','k','l','m','n','o','p',
    'q','r','s','t','u','v','w','x',
    'y','z','A','B','C','D','E','F',
    'G','H','I','J','K','L','M','N',
    'O','P','Q','R','S','T','U','V',
    'W','X','Y','Z',',','.','á','é',
    'í','ó','ú','Á','É','Í','Ó','Ú'
], dtype=str).reshape((8, 8))

def encriptar_con_polibio(frase: str) -> str:
    frase_encriptada = ""
    for char in frase:
        indices = (CUADRADO_DE_POLIBIO == char).nonzero()
        if indices[0].size > 0:
            fila, columna = indices[0][0], indices[1][0]
            frase_encriptada += f"{fila}{columna}"
        else:
            frase_encriptada += char
    return frase_encriptada.strip()
    

print("Frase original:")
print(FRASE)
print("\nFrase encriptada con Vigenere:")
frase_encriptada = encriptar_con_vigenere(FRASE, CLAVE)
print(frase_encriptada)

print("\nFrase encriptada con Polibio:")
frase_encriptada_polibio = encriptar_con_polibio(FRASE)
print(frase_encriptada_polibio)