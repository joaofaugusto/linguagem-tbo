variaveis = {}

def processarLinha(linha):
    partes = linha.strip().split()

    try:
        primeiroElementoLista = int(partes[0])
        operador = partes[1]
        segundoElementoLista = int(partes[2])

        if operador == "+":
            resultado = primeiroElementoLista + segundoElementoLista
        elif operador == "-":
            resultado = primeiroElementoLista - segundoElementoLista
        elif operador == "*":
            resultado = primeiroElementoLista * segundoElementoLista
        elif operador == "/":
            resultado = primeiroElementoLista / segundoElementoLista

        return resultado
    except (ValueError, IndexError):
        pass

    try:
        comando = str(partes[0])

        if comando == "variavel":
            nomevar = str(partes[1])
            valor = int(partes[3])
            variaveis[nomevar] = valor
        elif comando == "mostrar":
            texto = ' '.join(partes[1:])
            if texto in variaveis:
                print(variaveis[texto])
            else:
                print(texto)
        elif comando in variaveis:
            if partes[1] == "+":
                outra_variavel = str(partes[2])
                if outra_variavel in variaveis:
                    resultado = variaveis[comando] + variaveis[outra_variavel]
                    print(resultado)
            if partes[1] == "-":
                outra_variavel = str(partes[2])
                if outra_variavel in variaveis:
                    resultado = variaveis[comando] - variaveis[outra_variavel]
                    print(resultado)
            if partes[1] == "*":
                outra_variavel = str(partes[2])
                if outra_variavel in variaveis:
                    resultado = variaveis[comando] * variaveis[outra_variavel]
                    print(resultado)
            if partes[1] == "/":
                outra_variavel = str(partes[2])
                if outra_variavel in variaveis:
                    resultado = variaveis[comando] / variaveis[outra_variavel]
                    print(resultado)
    except (ValueError, IndexError):
        pass


def lerComandos():
    with open("a.tbo", "r") as comandos:
        return comandos.readlines()

def main():
    listaComandos = lerComandos()
    operacoes = []

    for linha in listaComandos:
        resultado = processarLinha(linha)
        if resultado is not None:
            operacoes.append(resultado)

if __name__ == "__main__":
    main()
