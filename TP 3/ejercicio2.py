import math

A = (math.sqrt(5) - 1) / 2  # Constante utilizada en el método de la multiplicación

def hashMultiplicacion(k: int, m: int) -> int:
    """
    Calcula la clave hash para un entero k utilizando el método de la mnultiplicación, considerando que la tabla tiene tamaño m.

    Parámetros:
        - k (int): El entero a hashear.
        - m (int): El tamaño de la tabla hash.
    Retorna:
        - int: La clave hash resultante.
    Precondiciones:
        - m > 0
        - m es potencia de 2
    """
    return math.floor(m * ((k * A) % 1))

# Main
valores = [10168, 21362, 8515, 7993, 32434, 29786, 35175, 50255, 32305, 24971, 10177, 53101, 12901]
print("Valores\tHash")
for v in valores:
    print(f"{v}\t{hashMultiplicacion(v, 256)}")