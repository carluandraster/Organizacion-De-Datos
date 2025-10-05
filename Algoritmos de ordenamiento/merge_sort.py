def merge_sort(arr: list) -> list:
    """"
    Recibe una lista desordenada y la ordena por el método Merge Sort
    Pre: arr es distinto de None y tiene al menos un elemento
    
    Parámetros:
        - arr (list): lista desordenada
        
    Retorna: lista ordenada
    """
    auxiliar1, auxiliar2: list
    insertarEnAuxiliar1 = True
    esta_ordenado = False
    
    while not esta_ordenado:
        vc = arr[0]
        esta_ordenado = True
        for i in range(1, len(arr)):
            if arr[i] < vc:
                vc = arr[i]
                insertarEnAuxiliar1 = not insertarEnAuxiliar1
                esta_ordenado = False
            if insertarEnAuxiliar1:
                auxiliar1.append(arr[i])
            else:
                auxiliar2.append(arr[i])