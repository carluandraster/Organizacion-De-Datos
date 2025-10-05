def merge_sort(origen: list) -> list:
    """
    Recibe una lista desordenada y la ordena por el método Merge Sort
    Pre: origen es distinto de None y tiene al menos un elemento
    
    Parámetros:
        - origen (list): lista desordenada
        
    Retorna: lista ordenada
    """
    auxiliar1, auxiliar2 = [], []
    insertarEnAuxiliar1 = True
    esta_ordenado = False
    
    while not esta_ordenado:
        esta_ordenado = True # La lista está ordenada hasta que se demuestre lo contrario
        auxiliar1.append(origen[0])
        for i in range(1, len(origen)):
            if origen[i] < origen[i-1]:  # Si el elemento actual es menor que el anterior, no está ordenado
                insertarEnAuxiliar1 = not insertarEnAuxiliar1
                esta_ordenado = False
            if insertarEnAuxiliar1:
                auxiliar1.append(origen[i])
            else:
                auxiliar2.append(origen[i])
        if not esta_ordenado:
            origen.clear()
            primera_subiteracion1 = True
            primera_subiteracion2 = True
            i = 0
            j = 0
            while i < len(auxiliar1) or j < len(auxiliar2):
                while i < len(auxiliar1) or j < len(auxiliar2) or i == 0 or auxiliar1[i] > auxiliar1[i-1] or j == 0 or auxiliar2[j] > auxiliar2[j-1]:
                    if (primera_subiteracion1 or auxiliar1[i] > auxiliar1[i-1]) and (primera_subiteracion2 or auxiliar2[j] > auxiliar2[j-1]):
                        if auxiliar1[i] < auxiliar2[j]:
                            origen.append(auxiliar1[i])
                            i += 1
                            primera_subiteracion1 = False
                        else:
                            origen.append(auxiliar2[j])
                            j += 1
                            primera_subiteracion2 = False
                    elif i == 0 or auxiliar1[i] > auxiliar1[i-1] or j == len(auxiliar2):
                        origen.append(auxiliar1[i])
                        i += 1
                    else:
                        origen.append(auxiliar2[j])
                        j += 1
    return origen

# Ejemplo de uso
print(merge_sort([38, 27, 43, 3, 9, 82, 10]))