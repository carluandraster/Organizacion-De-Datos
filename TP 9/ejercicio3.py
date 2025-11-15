from vigenere import encriptar_con_vigenere, ALFABETO
from numpy import array

FRASE = "El cifrado Cesar, es una de las tecnicas mas simples; consiste en reemplazar cada letra por otra que se encuentra un numero fijo de posiciones mas adelante."
FRASE_POLIBIO = "El cifrado César, es una de las técnicas más simples; consiste en reemplazar cada letra por otra que se encuentra un número fijo de posiciones más adelante."
CLAVE = "Ventilado"
CLAVE_CONFEDERADOS = "julio"
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

def metodo_de_confederados(frase: str, clave: str) -> str:
    i = 0
    frase_encriptada = ""
    for char in frase:
        if char in ALFABETO:
            indice_frase = ALFABETO.index(char)
            indice_clave = ALFABETO.index(clave[i % len(clave)])
            nuevo_indice = (indice_frase + indice_clave) % len(ALFABETO)
            frase_encriptada += ALFABETO[nuevo_indice]
            i += 1
        else:
            frase_encriptada += char
    return frase_encriptada

print("Frase original:")
print(FRASE)
print("\nFrase encriptada con Vigenere:")
frase_encriptada = encriptar_con_vigenere(FRASE, CLAVE)
print(frase_encriptada)

print("\nFrase encriptada con Polibio:")
frase_encriptada_polibio = encriptar_con_polibio(FRASE_POLIBIO)
print(frase_encriptada_polibio)

print("\nFrase encriptada con el Metodo de los Confederados:")
frase_encriptada_confederados = metodo_de_confederados(FRASE, CLAVE_CONFEDERADOS)
print(frase_encriptada_confederados)