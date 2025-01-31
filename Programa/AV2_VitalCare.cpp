// Autor: Álvaro Gabriel Alves Albuquerque
// Criado em: 2023
// Apenas para exibição e estudo

#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

int main(){
    int escolha,tempo;
    string Busca;
    bool Achou=false;
    //
    vector<string> pacientesCons;
    vector<string> datasCons;
    vector<string> horariosCons;
    vector<string> motivosCons;
    //
    vector<string> pacientesPront;
    vector<string> nascimentosPront;
    vector<string> sexosPront;
    vector<string> maesPront;
    vector<string> paisPront;
    vector<string> naturalidadesPront;
    vector<string> enderecosPront;
    //
    vector<string> pacientesAcomp;
    vector<int> consultasAcomp;
    vector<int> internacoesAcomp;
    vector<string> estadosAcomp;
    vector<string> riscosAcomp;
    vector<string> prioridadesAcomp;
    vector<string> doencasAcomp;
    vector<string> alergiasAcomp;
    vector<string> acompanhantesAcomp;
    vector<string> anotacoesAcomp;
    do{
        cout<<"=======================================================================================================================\n";
        cout<<"\t\t\t\t      SISTEMA DE GESTAO DE PACIENTES DA VITAL CARE\n\n";
        cout<<"\t\t\t\t\t      Menu de servicos do programa:\n";
        cout<<"\t\t\t\t\t      1 - Agendamento de Consultas\n";
        cout<<"\t\t\t\t\t      2 - Gerenciamento de Prontuarios\n";
        cout<<"\t\t\t\t\t      3 - Acompanhamento de Casos\n";
        cout<<"\t\t\t\t\t      0 - Sair do programa\n";
        cout<<"\t\t\t\t\t      Digite o numero do servico: ";
        cin>>escolha;
        cout<<"=======================================================================================================================\n";
        cout<<"=======================================================================================================================\n";
        switch(escolha){
            case 0: {
                cout<<"\t\t\t\t\t\t\tSaindo...";
                cout<<"\n=======================================================================================================================\n";
                break;
            }case 1: {
                int escolhaCons;
                string Nome,Data,Hora,Razao;
                bool tempoRepetido=false;
                do{
                    cout<<"\n\t\t\t\t\t       ---------- // ----------\n";
                    cout<<"\t\t\t\t\t       AGENDAMENTO DE CONSULTAS\n\n";
                    cout<<"\t\t\t\t\t      Menu de Opcoes do servico:\n";
                    cout<<"\t\t\t\t\t      1 - Agendar Consulta\n";
                    cout<<"\t\t\t\t\t      2 - Mostrar Consultas\n";
                    cout<<"\t\t\t\t\t      3 - Editar Consulta\n";
                    cout<<"\t\t\t\t\t      4 - Cancelar Consulta\n";
                    cout<<"\t\t\t\t\t      0 - Sair deste servico\n";
                    cout<<"\t\t\t\t\t      Digite o numero da opcao: ";
                    cin>>escolhaCons; cin.ignore();
                    switch(escolhaCons){
                        case 0: {
                            cout<<"\n=======================================================================================================================\n";
                            system("cls");
                            break;
                        }case 1: {
                            cout<<"\nNome completo do paciente: ";
                            getline(cin, Nome);
                            do{
                                tempoRepetido=false;
                                cout<<"Data da consulta (dd/mm/aaaa): ";
                                getline(cin, Data);
                                cout<<"Hora da consulta (hh:mm): ";
                                getline(cin, Hora);
                                if(!pacientesCons.empty()){
                                    for(int i=0; i<pacientesCons.size(); i++){
                                        if(datasCons[i] == Data && horariosCons[i] == Hora){
                                            cout<<"Outra consulta ja foi marcada neste horario, neste dia! Tente Novamente.\n\n";
                                            tempoRepetido=true;
                                        }
                                    }
                                }
                            }while(tempoRepetido == true);
                            cout<<"Razao da consulta: ";
                            getline(cin, Razao);
                            pacientesCons.push_back(Nome);
                            datasCons.push_back(Data);
                            horariosCons.push_back(Hora);
                            motivosCons.push_back(Razao);
                            cout<<"Consulta agendada com sucesso!\n";
                            break;
                        }case 2: {
                            if(pacientesCons.empty()){
                                cout<<"\nNao ha consultas agendadas.\n";
                            }else{
                                for(int i=0; i<pacientesCons.size(); i++){
                                    cout<<"\nNome do paciente: "<<pacientesCons[i]<<endl;;
                                    cout<<"Data da consulta: "<<datasCons[i]<<endl;
                                    cout<<"Horario da consulta: "<<horariosCons[i]<<endl;
                                    cout<<"Razao da consulta: "<<motivosCons[i]<<endl;
                                }
                            }
                            break;
                        }case 3: {
                            if(pacientesCons.empty()){
                                cout<<"\nNao ha consultas agendadas.\n";
                            }else{
                                Achou=false;
                                cout<<"\nDigite o nome completo do paciente: ";
                                getline(cin, Busca);
                                for(int i=0; i<pacientesCons.size(); i++){
                                    if(pacientesCons[i] == Busca){
                                        cout<<"\nNome completo do paciente: ";
                                        getline(cin, Nome);
                                        do{
                                            tempoRepetido=false;
                                            cout<<"Data da consulta (dd/mm/aaaa): ";
                                            getline(cin, Data);
                                            cout<<"Hora da consulta (hh:mm): ";
                                            getline(cin, Hora);
                                            for(int i=0; i<pacientesCons.size(); i++){
                                                if(datasCons[i] == Data && horariosCons[i] == Hora){
                                                    cout<<"Outra consulta ja foi marcada neste horario, neste dia! Tente Novamente.\n\n";
                                                    tempoRepetido=true;
                                                }
                                            }
                                        }while(tempoRepetido == true);
                                        cout<<"Razao da consulta: ";
                                        getline(cin, Razao);
                                        pacientesCons[i] = Nome;
                                        datasCons[i] = Data;
                                        horariosCons[i] = Hora;
                                        motivosCons[i] = Razao;
                                        cout<<"Consulta editada!\n";
                                        Achou=true;
                                        break;
                                    }
                                }
                                if(Achou == false)
                                    cout<<"Paciente nao encontrado!\n";
                            }
                            break;
                        }case 4: {
                            if(pacientesCons.empty()){
                                cout<<"\nNao ha consultas agendadas.\n";
                            }else{
                                Achou=false;
                                cout<<"\nDigite o nome completo do paciente: ";
                                getline(cin, Busca);
                                for(int i=0; i<pacientesCons.size(); i++){
                                    if(pacientesCons[i] == Busca){
                                        pacientesCons.erase(pacientesCons.begin()+i);
                                        datasCons.erase(datasCons.begin()+i);
                                        horariosCons.erase(horariosCons.begin()+i);
                                        motivosCons.erase(motivosCons.begin()+i);
                                        cout<<"Consulta cancelada!\n";
                                        Achou=true;
                                        break;
                                    }
                                }
                                if(Achou == false)
                                    cout<<"Paciente nao encontrado!\n";
                            }
                            break;
                        }default:{
                            cout<<"\nOpcao invalida! Tente novamente.\n";
                            break;
                        }
                    }
                }while(escolhaCons != 0);
                break;
            }case 2: {
                int escolhaPront;
                string Nome,Nasc,Sexo,NMae,NPai,Nat,End;
                do{
                    cout<<"\n\t\t\t\t\t       ------------ // ------------\n";
                    cout<<"\t\t\t\t\t       GERENCIAMENTO DE PRONTUARIOS\n\n";
                    cout<<"\t\t\t\t\t      Menu de Opcoes do servico:\n";
                    cout<<"\t\t\t\t\t      1 - Criar novo Prontuario\n";
                    cout<<"\t\t\t\t\t      2 - Pesquisar por um Prontuario\n";
                    cout<<"\t\t\t\t\t      3 - Editar Prontuario existente\n";
                    cout<<"\t\t\t\t\t      0 - Sair deste servico\n";
                    cout<<"\t\t\t\t\t      Digite o numero da opcao: ";
                    cin>>escolhaPront; cin.ignore();
                    switch(escolhaPront){
                        case 0: {
                            cout<<"\n=======================================================================================================================\n";
                            system("cls");
                            break;
                        }case 1: {
                            cout<<"\nNome completo do paciente: ";
                            getline(cin, Nome);
                            cout<<"Data de nascimento (dd/mm/aaaa): ";
                            getline(cin, Nasc);
                            cout<<"Sexo (Masculino/Feminino): ";
                            getline(cin, Sexo);
                            cout<<"Nome completo da mae: ";
                            getline(cin, NMae);
                            cout<<"Nome completo do pai: ";
                            getline(cin, NPai);
                            cout<<"Naturalidade do paciente: ";
                            getline(cin, Nat);
                            cout<<"Endereco completo do paciente (Estado, cidade, bairro, rua, CEP, numero e complemento*):\n";
                            getline(cin, End);
                            pacientesPront.push_back(Nome);
                            nascimentosPront.push_back(Nasc);
                            sexosPront.push_back(Sexo);
                            maesPront.push_back(NMae);
                            paisPront.push_back(NPai);
                            naturalidadesPront.push_back(Nat);
                            enderecosPront.push_back(End);
                            cout<<"\n*Anamnese*\n*Plano terapeutico*\n*Laudos de exames*\n*Prescricao medica*";
                            cout<<"\n*Evolucao medica e da enfermagem*\n*Termos de consetimentos*";
                            cout<<"\n*Sumario de transferencia, alta ou obito*\n*Documentos diversos especificos*\n";
                            cout<<"\nProntuario criado com sucesso!\n";
                            break;
                        }case 2: {
                            if(pacientesPront.empty()){
                                cout<<"\nNao ha prontuarios criados.\n";
                            }else{
                                Achou=false;
                                cout<<"\nDigite o nome completo do paciente: ";
                                getline(cin, Busca);
                                for(int i=0; i<pacientesPront.size(); i++){
                                    if(pacientesPront[i] == Busca){
                                        cout<<"Nome: "<<pacientesPront[i]<<endl;
                                        cout<<"Data de nascimento: "<<nascimentosPront[i]<<endl;
                                        cout<<"Sexo: "<<sexosPront[i]<<endl;
                                        cout<<"Mae: "<<maesPront[i]<<endl;
                                        cout<<"Pai: "<<paisPront[i]<<endl;
                                        cout<<"Naturalidade: "<<naturalidadesPront[i]<<endl;
                                        cout<<"Endereco: "<<enderecosPront[i]<<endl;
                                        cout<<"\n*Anamnese*\n*Plano terapeutico*\n*Laudos de exames*\n*Prescricao medica*";
                                        cout<<"\n*Evolucao medica e da enfermagem*\n*Termos de consetimentos*";
                                        cout<<"\n*Sumario de transferencia, alta ou obito*\n*Documentos diversos especificos*\n";
                                        Achou=true;
                                        break;
                                    }
                                }
                                if(Achou == false)
                                    cout<<"Paciente nao encontrado!\n";
                            }
                            break;
                        }case 3: {
                            if(pacientesPront.empty()){
                                cout<<"\nNao ha prontuarios criados.\n";
                            }else{
                                Achou=false;
                                cout<<"\nDigite o nome completo do paciente: ";
                                getline(cin, Busca);
                                for(int i=0; i<pacientesPront.size(); i++){
                                    if(pacientesPront[i] == Busca){
                                        cout<<"\nNome completo do paciente: ";
                                        getline(cin, Nome);
                                        cout<<"Data de nascimento (dd/mm/aaaa): ";
                                        getline(cin, Nasc);
                                        cout<<"Sexo (Masculino/Feminino): ";
                                        getline(cin, Sexo);
                                        cout<<"Nome completo da mae: ";
                                        getline(cin, NMae);
                                        cout<<"Nome completo do pai: ";
                                        getline(cin, NPai);
                                        cout<<"Naturalidade do paciente: ";
                                        getline(cin, Nat);
                                        cout<<"Endereco completo do paciente (Estado, cidade, bairro, rua, CEP, numero e complemento*):\n";
                                        getline(cin, End);
                                        pacientesPront[i] = Nome;
                                        nascimentosPront[i] = Nasc;
                                        sexosPront[i] = Sexo;
                                        maesPront[i] = NMae;
                                        paisPront[i] = NPai;
                                        naturalidadesPront[i] = Nat;
                                        enderecosPront[i] = End;
                                        cout<<"\n*Anamnese*\n*Plano terapeutico*\n*Laudos de exames*\n*Prescricao medica*";
                                        cout<<"\n*Evolucao medica e da enfermagem*\n*Termos de consetimentos*";
                                        cout<<"\n*Sumario de transferencia, alta ou obito*\n*Documentos diversos especificos*\n";
                                        cout<<"\nProntuario editado!\n";
                                        Achou=true;
                                        break;
                                    }
                                }
                                if(Achou == false)
                                    cout<<"Paciente nao encontrado!\n";
                            }
                            break;
                        }default: {
                            cout<<"\nOpcao invalida! Tente novamente.\n";
                            break;
                        }
                    }
                }while(escolhaPront != 0);
                break;
            }case 3: {
                int escolhaAcomp;
                string Nome,Estado,Risco,Prioridade,Acompanhante,Doenca,Alergia,Anotacao;
                int numConsulta,numInternacao;
                do{
                    cout<<"\n\t\t\t\t\t       ---------- // ----------\n";
                    cout<<"\t\t\t\t\t       Acompanhamento de Casos\n\n";
                    cout<<"\t\t\t\t\t      Menu de Opcoes do servico:\n";
                    cout<<"\t\t\t\t\t      1 - Acompanhar novo Caso\n";
                    cout<<"\t\t\t\t\t      2 - Exibir Caso existente\n";
                    cout<<"\t\t\t\t\t      3 - Editar Caso existente\n";
                    cout<<"\t\t\t\t\t      0 - Sair deste servico\n";
                    cout<<"\t\t\t\t\t      Digite o numero da opcao: ";
                    cin>>escolhaAcomp; cin.ignore();
                    switch(escolhaAcomp){
                        case 0: {
                            cout<<"\n=======================================================================================================================\n";
                            system("cls");
                            break;
                        }case 1: {
                            cout<<"\nNome completo do paciente: ";
                            getline(cin, Nome);
                            cout<<"Numero de vezes que ja foi consultado: ";
                            cin>>numConsulta; cin.ignore();
                            cout<<"Numero de vezes que ja foi internado: ";
                            cin>>numInternacao; cin.ignore();
                            cout<<"Opcoes de estado do paciente:\n";
                            cout<<"Saudavel / Alerta / Doente / Acidentado / Internado / Coma / Obito\n";
                            cout<<"Digite o estado do paciente: ";
                            getline(cin, Estado); 
                            cout<<"Classificacoes de risco do caso:\n";
                            cout<<"Azul - nao urgente / Verde - pouco urgente / Amarelo - urgente / Laranja - muito urgente / Vermelho - emergente\n";
                            cout<<"Digite a cor da classificacao de risco: ";
                            getline(cin, Risco);
                            cout<<"Prioridades de atendimento do paciente:\n";
                            cout<<"Nenhum / Deficiente / Idoso / Gestante / Pessoa com crianca de colo / Autista\n";
                            cout<<"Digite a prioridade do atendimento do paciente: ";
                            getline(cin, Prioridade);
                            cout<<"Doenca(s) do paciente: ";
                            getline(cin, Doenca);
                            cout<<"Alergia(s) do paciente: ";
                            getline(cin, Alergia);
                            cout<<"Acompanhante(s): ";
                            getline(cin, Acompanhante);
                            cout<<"Anotacoes do(s) medico(s): ";
                            getline(cin, Anotacao);
                            pacientesAcomp.push_back(Nome);
                            consultasAcomp.push_back(numConsulta);
                            internacoesAcomp.push_back(numInternacao);
                            estadosAcomp.push_back(Estado);
                            riscosAcomp.push_back(Risco);
                            prioridadesAcomp.push_back(Prioridade);
                            doencasAcomp.push_back(Doenca);
                            alergiasAcomp.push_back(Alergia);
                            acompanhantesAcomp.push_back(Acompanhante);
                            anotacoesAcomp.push_back(Anotacao);
                            cout<<"Caso adicionado com sucesso!\n";
                            break;
                        }case 2: {
                            if(pacientesAcomp.empty()){
                                cout<<"\nNao ha casos adicionados.\n";
                            }else{
                                Achou=false;
                                cout<<"\nDigite o nome completo do paciente: ";
                                getline(cin, Busca);
                                for(int i=0; i<pacientesAcomp.size(); i++){
                                    if(pacientesAcomp[i] == Busca){
                                        cout<<"Nome: "<<pacientesAcomp[i]<<endl;
                                        cout<<"Consultas: "<<consultasAcomp[i]<<endl;
                                        cout<<"Internacoes: "<<internacoesAcomp[i]<<endl;
                                        cout<<"Estado do paciente: "<<estadosAcomp[i]<<endl;
                                        cout<<"Classificacao de risco do caso: "<<riscosAcomp[i]<<endl;
                                        cout<<"Prioridade de atendimento do paciente: "<<prioridadesAcomp[i]<<endl;
                                        cout<<"Doenca(s): "<<doencasAcomp[i]<<endl;
                                        cout<<"Alergia(s): "<<alergiasAcomp[i]<<endl;
                                        cout<<"Acompanhante(s): "<<acompanhantesAcomp[i]<<endl;
                                        cout<<"Anotacoes do(s) medico(s): "<<anotacoesAcomp[i]<<endl;
                                        Achou=true;
                                    }
                                }
                                if(Achou == false)
                                    cout<<"Paciente nao encontrado!\n";
                            }
                            break;
                        }case 3: {
                            if(pacientesAcomp.empty()){
                                cout<<"\nNao ha casos adicionados.\n";
                            }else{
                                Achou=false;
                                cout<<"\nDigite o nome completo do paciente: ";
                                getline(cin, Busca);
                                for(int i=0; i<pacientesAcomp.size(); i++){
                                    if(pacientesAcomp[i] == Busca){
                                        cout<<"\nNome completo do paciente: ";
                                        getline(cin, Nome);
                                        cout<<"Numero de vezes que ja foi consultado: ";
                                        cin>>numConsulta; cin.ignore();
                                        cout<<"Numero de vezes que ja foi internado: ";
                                        cin>>numInternacao; cin.ignore();
                                        cout<<"Opcoes de estado do paciente:\n";
                                        cout<<"Saudavel / Alerta / Doente / Acidentado / Internado / Coma / Obito\n";
                                        cout<<"Digite o estado do paciente: ";
                                        getline(cin, Estado); 
                                        cout<<"Classificacoes de risco do caso:\n";
                                        cout<<"Azul - nao urgente / Verde - pouco urgente / Amarelo - urgente / Laranja - muito urgente / Vermelho - emergente\n";
                                        cout<<"Digite a cor da classificacao de risco: ";
                                        getline(cin, Risco);
                                        cout<<"Prioridades de atendimento do paciente:\n";
                                        cout<<"Nenhum / Deficiente / Idoso / Gestante / Pessoa com crianca de colo / Autista\n";
                                        cout<<"Digite a prioridade do atendimento do paciente: ";
                                        getline(cin, Prioridade);
                                        cout<<"Doenca(s) do paciente: ";
                                        getline(cin, Doenca);
                                        cout<<"Alergia(s) do paciente: ";
                                        getline(cin, Alergia);
                                        cout<<"Acompanhante(s): ";
                                        getline(cin, Acompanhante);
                                        cout<<"Anotacoes do(s) medico(s): ";
                                        getline(cin, Anotacao);
                                        pacientesAcomp.push_back(Nome);
                                        consultasAcomp.push_back(numConsulta);
                                        internacoesAcomp.push_back(numInternacao);
                                        estadosAcomp.push_back(Estado);
                                        riscosAcomp.push_back(Risco);
                                        prioridadesAcomp.push_back(Prioridade);
                                        doencasAcomp.push_back(Doenca);
                                        alergiasAcomp.push_back(Alergia);
                                        acompanhantesAcomp.push_back(Acompanhante);
                                        anotacoesAcomp.push_back(Anotacao);
                                        cout<<"Caso editado!\n";
                                        Achou=true;
                                    }
                                }
                                if(Achou == false)
                                    cout<<"Paciente nao encontrado!\n";
                            }
                            break;
                        }default: {
                            cout<<"\nOpcao invalida! Tente novamente.\n";
                            break;
                        }
                    }
                }while(escolhaAcomp !=0);
                break;
            }default: {
                cout<<"\t\t\t\t\t      Opcao invalida! Tente Novamente.\n";
                cout<<"=======================================================================================================================\n";
                break;
            }
        }
    }while(escolha != 0);
    tempo = clock();
    while(clock()-tempo <5000){}
    return 0;
}