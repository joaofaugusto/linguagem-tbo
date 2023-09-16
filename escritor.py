def processar_linha(linha):
    partes = linha.strip().split()
    operacao = {}
    
    try:
        pil = int(partes[0])
        operador = partes[1]
        sil = int(partes[2])

        if operador == "+":
            operacao = {
                "expressao": {
                    "tipo": "soma",
                    "valor": {
                        "tipo": "int",
                        "conteudo": {
                            "um": pil,
                            "dois": sil
                        }
                    }
                }
            }
        elif operador == "-":
            operacao = {
                "expressao": {
                    "tipo": "sub",
                    "valor": {
                        "tipo": "int",
                        "conteudo": {
                            "um": pil,
                            "dois": sil
                        }
                    }
                }
            }
        elif operador == "*":
            operacao = {
                "expressao": {
                    "tipo": "mul",
                    "valor": {
                        "tipo": "int",
                        "conteudo": {
                            "um": pil,
                            "dois": sil
                        }
                    }
                }
            }
    except (ValueError, IndexError):
        pass

    return operacao

def ler_comandos():
    with open("a.tbo", "r") as comandos:
        return comandos.readlines()

def main():
    lista_comandos = ler_comandos()
    operacoes = []

    for linha in lista_comandos:
        operacao = processar_linha(linha)
        if operacao:
            operacoes.append(operacao)


if __name__ == "__main__":
    main()
