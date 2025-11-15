from vigenere import encriptar_con_vigenere

FRASE = "El cifrado Cesar, es una de las tecnicas mas simples; consiste en reemplazar cada letra por otra que se encuentra un numero fijo de posiciones mas adelante."
CLAVE = "Ventilado"

print("Frase original:")
print(FRASE)
print("\nFrase encriptada:")
frase_encriptada = encriptar_con_vigenere(FRASE, CLAVE)
print(frase_encriptada)