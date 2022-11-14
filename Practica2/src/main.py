import sys

def main():
    sigma = [ "a", "b", "c" ]
    aux = ""
    w1 = ""
    w2 = ""

    print("Sigma por defecto es { a,b,c }, ingresa una diferente si gustas")
    print("Ejemplo 'sigma = a,d,e', presiona enter si no quieres cambiarlo|")
    print("Ingresa tu alfabeto -> sigma = ", end = "")
    aux = input()
    if aux != "":
        aux = aux.replace(" ", "")
        aux = aux.split(",")
        sigma = aux
    print("Ingresa la palabra w1 = ", end = "")
    w1 = input()
    print("Ingresa la palabra w2 = ", end = "")
    w2 = input()
    if not verifyString(w1, sigma) and not verifyString(w2, sigma):
        print("Tus cadenas ingresadas no tiene tu lenguaje")
        sys.exit()
    opc = menu()
    if opc == 1:
        opc = submenu_concat()
        if opc == 1:
            print(f"w1w2 = {w1} * {w2} = {w1 + w2}")
        elif opc == 2:
            print(f"w2w1 = {w2} * {w1} = {w2 + w1}")
        elif opc == 3:
            print(f"w2w2 = {w2} * {w2} = {w2 + w2}")
        else:
            print("Opcion no encontrada")
            sys.exit()
    elif opc == 2:
        opc = submenu_long()
        if opc == 1:
            print(f"|w1| = {len(w1)}")
        elif opc == 2:
            print(f"|w1w2| = |{w1 + w2}| = {len(w1 + w2)}")
        else:
            print("Opcion no encontrada")
            sys.exit()
    elif opc == 3:
        print("Ingresa la potnecia n = ", end="")
        print(potencia(int(input()), w1)) #w1
    elif opc == 4:
        print("PREFIJO")
        prefijo(w2)
        print("SUFIJO")
        sufijo(w2)
    else:
        print("Opcion no encontrada")
        sys.exit()
    
def menu():
    print("1 -> Concatenacion")
    print("2 -> Longitud")
    print("3 -> Potencia")
    print("4 -> Prefijos/Sufijos -> w2")
    print("Ingresa tu opcion -> ", end="")
    opc = input()
    return int(opc)

def submenu_concat():
    print("1 -> w1w2")
    print("2 -> w2w1")
    print("3 -> w2w2")
    print("Ingresa la opcion deseada -> ", end="")
    opc = input()
    return int(opc)

def submenu_long():
    print("1 -> |w1|")
    print("2 -> |w1w2|")
    print("Ingresa la opcion deseada -> ", end="")
    opc = input()
    return opc

def potencia(n, string):
    if n > 0:
        return string * n
    elif n == 0:
        return "(CADENA_VACIA)"
    else:
        return str(string[::-1])*(n*-1)

def prefijo(string):
    prefijo = ""
    print("(Void)")
    for char in string:
        prefijo += char
        print(prefijo)

def sufijo(string):
    sufijo = ""
    print("(Void)")
    for char in string[::-1]:
        sufijo += char
        print(sufijo) 

def verifyString(string, sigma):
    for char in string:
        for sigmaChar in sigma:
            if char == sigmaChar:
                return True
    return False

if __name__ == "__main__":
    main()