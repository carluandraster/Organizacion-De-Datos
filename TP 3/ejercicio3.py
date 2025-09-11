def es_primo(num: int) -> bool:
    """
    Devuelve True si num es primo, False en caso contrario.
    
    Un número primo es un número mayor que 1 que solo es divisible por 1 y por sí mismo.
    
    Parametros:
        - num (int): El número a verificar.
    Retorna:
        - bool: True si num es primo, False en caso contrario.
    """
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def hash_por_compresion(k: str, m: int) -> int:
    """
    Implementa una función de hash por compresión.
    
    La función convierte cada carácter de la cadena k en su valor ASCII,
    aplica XOR a estos valores y luego aplica el módulo m para obtener un índice
    dentro del rango de la tabla hash.
    
    Parámetros:
        - k (str): La clave a ser hasheada.
        - m (int): El número primo más cercano de la tabla hash.
    Retorna:
        - int: El índice hasheado en el rango [0, m-1].
    Precondiciones:
        - k es una cadena no vacía y distina de None.
        - m es un número primo.
    """
    xor = ord(k[0])
    for c in k[1:]:
        xor ^= ord(c)
    return xor % m

# Main
m = 512
valores = ["limon", "gato", "vodka", "ojo", "ojota", "caradura", "caradura", "oh"]
while not es_primo(m):
    m += 1
print(f"Número primo más cercano a 512: {m}")
print("Valor\tHash")
for v in valores:
    print(f"{v}\t{hash_por_compresion(v, m)}")