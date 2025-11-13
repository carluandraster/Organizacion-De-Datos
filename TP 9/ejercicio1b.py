from vigenere import encriptar_con_vigenere

FRASE = "No temo a los ordenadores, lo que temo es quedarme sin ellos. Isaac Asimov."
CLAVE = "ventilado"

print(encriptar_con_vigenere(FRASE, CLAVE))