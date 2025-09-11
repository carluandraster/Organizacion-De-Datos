def split(k: int)-> list[int]:
    """
    Dado un entero devuelve una lista con sus bytes (del menos significativo al más significativo)
    
    Ejemplo: split(123456) -> [64, 226, 1, 0]
    Parametros:
        k: entero a dividir en bytes
    Retorna: lista de bytes
    """
    return [ (k >> (i * 8)) & 0xFF for i in range(4) ]

def hashFoldAndAdd(k: int, m: int) -> int:
    """
    Hashea el entero k en el rango [0, m-1] usando el método de Fold & Adds
    
    Parametros:
        k: entero a hashear
        m: tamaño de la tabla hash
    Retorna: valor hasheado en el rango [0, m-1]
    Ejemplo: hashFoldAndAdd(123456, 100) -> 91
    """
    bytes = split(k)
    return sum(bytes) % m

# Main
valores = [10168, 21362, 8515, 7993, 32434, 29786, 35175, 50255, 32305, 24971, 10177, 53101, 12901]
print("Valor\t Hash")
for valor in valores:
    print(f"{valor}\t {hashFoldAndAdd(valor, 200)}")