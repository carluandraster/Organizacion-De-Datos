from numpy import array, empty

def cesar(mensaje: str, desplazamiento: int) -> str:
    resultado = ""
    for char in mensaje:
        if char.isalpha():
            desplazamiento_base = ord('A') if char.isupper() else ord('a')
            nuevo_char = chr((ord(char) - desplazamiento_base + desplazamiento) % 26 + desplazamiento_base)
            resultado += nuevo_char
        else:
            resultado += char
    return resultado

def cesar_con_palabra(mensaje: str, desplazamiento: int, palabra_clave: str) -> str:
    alfabeto = array([chr(i) for i in range(ord('A'), ord('N') + 1)])
    alfabeto = array(list(alfabeto) + ['Ñ'])
    alfabeto = array(list(alfabeto) + [chr(i) for i in range(ord('O'), ord('Z') + 1)])
    alfabeto_modificado = array([''] * 27)
    inicio = desplazamiento
    fin = desplazamiento+len(palabra_clave)
    i = inicio
    while i < fin:
        alfabeto_modificado[i] = palabra_clave[i - inicio]
        i += 1
    for letra in alfabeto:
        if letra not in alfabeto_modificado:
            alfabeto_modificado[i] = letra
            i += 1
            if i == 27:
                i = 0
    print(alfabeto_modificado)

cesar_con_palabra("", 5, "MURCIELAGO")