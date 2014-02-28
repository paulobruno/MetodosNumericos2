# 2014, Fortaleza, Ceara
#
# UNIVERSIDADE FEDERAL DO CEARA
# CURSO DE COMPUTACAO
# METODOS NUMERICOS II
# PROFESSORA: Emanuele Marques dos Santos
#
# Jose Orlando Barbosa Filho      336224
# Paulo Bruno de Sousa Serafim    354086

CC		= g++
CFLAGS	= -c
EXEC	= MnIntegration

SHOW	= ./

METHODS	= \
	IntegrationMethod.cpp \
	TrapeziumRule.cpp \
	Simpson13Rule.cpp \
	Simpson38Rule.cpp
	
UTILITY	= \
	MnTableReader.cpp 

SOURCES	= $(METHODS) $(UTILITY) main.cpp

OBJS	= $(SOURCES:.cpp = .o)

RM		= rm -rf

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $<

show: $(EXEC)
	$(SHOW)$(EXEC)

.PHONY: clean cleanall

clean:
	$(RM) *.o *~

cleanall:
	$(RM) $(EXEC) *.o *~

help:
	@echo "# "
	@echo "# ----- MAKE HELP -----"
	@echo "# "
	@echo "#     make           : comando padrao. Gera um arquivo executavel."
	@echo "#     make all       : o mesmo que make."
	@echo "#     make show      : executa o programa e mostra os resultados."
	@echo "#     make clean     : elimina os arquivos criados no processo"
	@echo "#                        de geracao do documento."
	@echo "#     make cleanall  : o mesmo que make clean e elimina tambem"
	@echo "#                        o arquivo executavel."
	@echo "#     make help      : mostra esta ajuda."
	@echo "# "
