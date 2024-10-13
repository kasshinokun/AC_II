#Para executar: python run main_apresentacao_exercicio_4.py

#Codigo template para o Exercício Prático 4 de Arquitetura de Computadores II
#previsao de entrega 7 de Outubro de 2024

#Caso haja comentários em inglês, é pois esqueci de(não deu para) traduzir 

#Prototipo em Python 
#Criado em 19-09-2024 Adaptado em 29-09-2024
# Revisão 1_07_10_2024

#import serial

#import serial.tools.list_ports

import os, io, re, subprocess, time, codecs, binascii 

from fnmatch import fnmatch

from binascii import unhexlify

from io import BytesIO

#----------------------------------------------------------------Localização do arquivo
def get_doc_folder():#Localiza a pasta documentos do windows ou linux
    # toget user
    user=os.path.join(os.environ['USERPROFILE'])
    # to get documents
    path_doc=str(os.path.join(os.path.join(user), 'Documents'))
    
    return path_doc

#Analise do mnemonico enviado versão 1
def set_op_code_alpha(mnemonic):
    
    pattern = re.compile(r'\s+')
    mnemonic = re.sub(pattern, '', mnemonic)
    
    #print(mnemonic)
    
    if mnemonic=='umL':
        return '0'
    elif mnemonic=='AonB':
        return '1'
    elif mnemonic=='copiaA':
        return '2'
    elif mnemonic=='nAxnB':
        return '3'
    elif mnemonic=='AeBn':
        return '4'
    elif mnemonic=='nA':
        return '5'
    elif mnemonic=='AenB':
        return '6'
    elif mnemonic=='nAonB':
        return '7'
    elif mnemonic=='AxB':
        return '8'
    elif mnemonic=='zeroL':
        return '9'
    elif mnemonic=='copiaB':
        return 'A'
    elif mnemonic=='AeB':
        return 'B'
    elif mnemonic=='nB':
        return 'C'
    elif mnemonic=='nAeBn':
        return 'D'
    elif mnemonic=='AoB':
        return 'E'
    elif mnemonic=='nAeB':
        return 'F'
    else:
        print ("not recognized")
        return -1
    
#Analise do mnemonico enviado versão 2
def set_op_code_beta(mnemonic):
    
    pattern = re.compile(r'\s+')
    mnemonic = re.sub(pattern, '', mnemonic)
    
    #print(mnemonic)
    
    dict_op_codes={
        'umL': '0',
        'AonB': '1',
        'copiaA': '2',
        'nAxnB': '3',
        'AeBn': '4',
        'nA': '5',
        'AenB': '6',
        'nAonB': '7',
        'AxB': '8',
        'zeroL': '9',
        'copiaB': 'A',
        'AeB': 'B',
        'nB': 'C',
        'nAeBn': 'D',
        'AoB': 'E',
        'nAeB': 'F'}
    try:
        return dict_op_codes.get(mnemonic)
    except Exception as errno:
        print ("not recognized ", errno)
        return None

def check_result(mnemonic,result): 
    
    if result==-1:
        print(("A chave %s não possui o valor associado. "%(mnemonic)))
    else:
        print("O Dicionário possui a chave: %s"%(mnemonic))
        print("e a chave %s possui o valor: %s"%(mnemonic,result)) 

def show_mnemonic():#Teste das 2 versões
    #mnemonico v1:
    mnemonic= 'umL'
    print("mnemonico v1")
    print("O Dicionário possui a chave: %s ?"%(mnemonic))
    result=set_op_code_alpha(mnemonic)
    check_result(mnemonic,result)    
    print()
    #mnemonico v2:
    print("mnemonico v2")
    print("O Dicionário possui a chave: %s ?"%(mnemonic))
    result2=set_op_code_beta(mnemonic)
    check_result(mnemonic,result2)

def generate_hex(list_96_op):#Escrita do arquivo .hex
    
    path_txt=get_doc_folder()+"\\ac_2_ep_04\\text.hex"# Caminho do arquivo

    if not os.path.exists(get_doc_folder()+"\\ac_2_ep_04"):#verificação da pasta
        os.makedirs(get_doc_folder()+"\\ac_2_ep_04")

    print("Escrita no caminho: ",path_txt) # Feedback
    
    with open(path_txt,"w") as arquivo: # Escrita do arquivo
        arquivo.write("".join(str(item) for item in list_96_op))
        #pickle..dump(list_96_op, arquivo)

def read_hex_test():# Leitura do arquivo .hex
    
    path_txt=get_doc_folder()+"\\ac_2_ep_04\\text.hex"# Caminho do arquivo

    if not os.path.exists(get_doc_folder()+"\\ac_2_ep_04"):# Feedback
        os.makedirs(get_doc_folder()+"\\ac_2_ep_04")

    print("Leitura no caminho: ",path_txt) # Feedback

    

def generate_op(x,y,w): #----------Gera a operação a ser gravada
    
    pattern = re.compile(r'\s+')
    x = re.sub(pattern, '', x)
    
    pattern = re.compile(r'\s+')
    y = re.sub(pattern, '', y)

    pattern = re.compile(r'\s+')
    w = re.sub(pattern, '', w)

    return (x+y+w)

# Baseado no path dado e no parametro 
# listará os arquivos dentro do local 
# e das subpastas
def list_files(path_f,pattern_f):
    
    #Configura variavel de caminho
    root = path_f
    
    #Configura variavel de padrão(extensão do arquivo a ser lido)
    pattern = pattern_f

    find_files=[] #Vetor de Strings
    list_96_op=[] # vetor de strings

    #Leitura e adição em um vetor de caminhos
    for path, subdirs, files in os.walk(root):
        
        for name in files:
            
            if fnmatch(name, pattern):
                
                file_p=os.path.join(path, name)
                
                find_files.append(file_p)
    
    #Exibe cada caminho encontrado
    for file_x in find_files:
        
        print(file_x)          
    
    #Leitura do caminho escolhido
    with open(find_files[0], "r") as fp:
        
        #Leitura da primeira linha
        lines = fp.readline()
        
        #Checagem
        if(('inicio:' in lines)|('Inicio:' in lines)):

            lines = fp.readlines()#Leitura das demais linhas
            #Inicializa as variáveis
            x=''
            y=''
            w=''
            for i in lines:
                
                if ((i =="fim." )|(i =="Fim.")): #se chegar o fim
                    
                    break#interrompe
                else:
                    
                    #print('Linha: ',i)#Exibe linha(Feedback)
                    
                    if('X=' in i):
                        x=re.sub("[x:,.X=;]","",i) # adiciona o valor de x
                        #Feedback
                        #print('X equivale a ',x)
                        #print('Y equivale a ',y)
                        #print('Linha: ',i)#Exibe linha(Feedback)
                    elif('Y=' in i):
                        y=re.sub("[y:,.Y=;]","",i) # adiciona o valor de x
                        #Feedback
                        #print('X equivale a ',x)
                        #print('Y equivale a ',y)
                        #print('Linha: ',i)#Exibe linha(Feedback)
                    elif('W=' in i):
                        print('Linha: ',i)#Exibe linha
                        w=re.sub("[w:,.W=;]","",i) # adiciona o valor de w
                        w=set_op_code_beta(w) #pega o opcode
                        #Feedback
                        #print('X equivale a ',x)
                        #print('Y equivale a ',y)
                        #print('W equivale a ',w)
                        operate=generate_op(x,y,w)
                        #print('Operacao: ',operate)
                        
                        list_96_op.append(operate) # gera a string e adiciona ao vetor de strings 
            #Feedback
            for opcode in list_96_op:
                print("operacao: ",opcode)  
            generate_hex(list_96_op)#Cria o arquivo .hex
                     
        else:
            
            print("wrong command text")#feedback

#Organize primeiro a pasta documentos antes da execução desta parte
def set_path_read():#Escolha do usuário para configurar o path do arquivo
    
    print("Set local to read:")
    print("1)--->Path")
    print("2)--->Users/Documents")
    result=input("Choose a option, please: ")
    if result==1:
        path_f=input("Set a path, please: ")
        list_files(path_f,"*.ula")
    elif result==2:
        list_files(get_doc_folder(),"*.ula")
    else:
        print ("not recognized")
        

#----------------------------------------------------------------(96 operações)
#converter para string e gravar
#-->use para treinar o programa
def read_txt(path_txt):#arquivo de texto
    with open(path_txt, "r") as arquivo:
        print(arquivo.read())


#---------------------------------------------------------------------------
def write_read_txt_3():#Préludio do arquivo
    try:
        print("Criando o arquivo")
        list_files(get_doc_folder(),"*.ula") #Escrita do arquivo
        print("Lendo o arquivo")
        read_txt(get_doc_folder()+"\\ac_2_ep_04\\text.hex")#Leitura do arquivo
    except Exception as errno:
        print("Erro was found")
        print(errno)

#Command to clear the terminal(Limpa o terminal)
os.system('cls' if os.name == 'nt' else 'clear')

#---------------------------------------------------------------------------Call function(Testes)
#---------------------------------------Orientações-------------------------------------------------
#Lista de funções para o exercicio

#-->get_doc_folder():#Localiza a pasta documentos do windows ou linux
#-->set_op_code_beta(mnemonic):#analisa e retorna o opcode
#-->read_txt(path_txt):#Leitura do arquivo .hex
#-->generate_op(x,y,w): #----------Gera a operação a ser gravada
#-->generate_hex(list_96_op):#Escrita do arquivo .hex
#-->list_files(get_doc_folder(),"*.ula") #Leitura do arquivo .txt(.ula) e escrita do arquivo .hex

write_read_txt_3() #Usem esta função e suas subfunções acima listadas por favor

#as demais foram apagadas pois eram apenas testes e feedback
