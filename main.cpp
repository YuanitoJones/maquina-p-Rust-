#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct TS
{
    string lexema;
    string valor;
    string direccion;
};


int main()
{
    std::string pila[30];
    int puntero=-1;
    string valor;
    string cadena;
    bool sw= false;
    string id;
    bool condicion=false;
    bool salto = false;
    string label;
    //Variables de for
    bool ffor=false;
    int base;
    int tope;
    string linea;
    string cmp;
    int contador=0;
    bool ujp=false;



    TS TSSimple [100];
    int punteroTS=0;

	ifstream fe;
	fe.open("C:\\compilador\\PCODE.txt");

    if (!fe)
    {
        exit(3);
        return 3;
    }

	while (!fe.eof())
	{
	    if(salto){
            fe >> id;
            if(label != id){
                continue;
            }
	    }
	    fe >> cadena;

        if (cadena == "lda") //asignar memoria
        {
            fe >> id;
            for (int x=0; x<punteroTS; x++)
            {
                if (id == TSSimple[x].lexema)
                {
                    if (TSSimple[x].direccion != ""){
                        pila[puntero] = TSSimple[x].direccion;
                    }
                    sw = true;
                    break;
                }
            }
            if (sw== false)
            {
                // tengo que traer una nueva direccionde memoria INSTRUCCION RM
                TSSimple[punteroTS].valor = "";
                TSSimple[punteroTS].lexema = id;
                puntero++;
                pila[puntero] = TSSimple[punteroTS].lexema;
                pila[puntero] = id;
                punteroTS++;
            }
            sw = false;
        }
        else if (cadena == "ldc")
        {
            fe >> id;
            puntero ++;
            pila[puntero] = id;
        }

        else if (cadena == "lod") //buscar en TS el valor de la variable
        {
             fe >> id;

            for (int x=0; x<punteroTS; x++)
            {
                if (id == TSSimple[x].lexema)
                {
                        puntero ++;
                        pila[puntero] = TSSimple[x].lexema + "{"+ TSSimple[x].valor +"}";
                        break;
                }
            }
        }
        else if (cadena == "sto")  // busqueda en gestores y guardar el valor en temporales
        {
            string temp1 = pila[puntero];
            pila[puntero]="";
            puntero --;
            string temp2 = pila[puntero];
            pila[puntero]="";

            for (int x=0; x<punteroTS; x++)
            {
                if (temp2 == TSSimple[x].lexema + "{"+ TSSimple[x].valor +"}" || temp2 == TSSimple[x].lexema)
                {
                        TSSimple[x].valor = temp1;
                        break;
                }
            }
            puntero--;
            // guardar con ensamblador debe de guardar a la direccion de memoria
        }
        else if (cadena == "adi")
        {
            int temp1;
            try{
                temp1 = stoi(pila[puntero]);
            }catch(std::invalid_argument& e){
                for (int x=0; x<punteroTS; x++)
                {
                    if (pila[puntero] == TSSimple[x].lexema + "{"+ TSSimple[x].valor +"}")
                    {

                        temp1 = stoi(TSSimple[x].valor);
                        break;
                    }
                }
            }
            pila[puntero] = "";
            puntero--;
            int temp2;
            try{
                temp2 = stoi(pila[puntero]);
            }catch(std::invalid_argument& e){
                for (int x=0; x<punteroTS; x++)
                {
                    if (pila[puntero] == TSSimple[x].lexema + "{"+ TSSimple[x].valor +"}")
                    {
                        temp2 = stoi(TSSimple[x].valor);
                        break;
                    }
                }
            }
            pila[puntero] = "";
            int resultado;

            __asm__ ( "addl %%ebx, %%eax;"
                    : "=a" (resultado)
                    : "a" (temp2), "b" (temp1) );


            pila[puntero] = std::to_string(resultado);

	}
	    else if (cadena == "sbi")
        {
            int temp1;
            try{
                temp1 = stoi(pila[puntero]);
            }catch(std::invalid_argument& e){
                for (int x=0; x<punteroTS; x++)
                {
                    if (pila[puntero] == TSSimple[x].lexema + "{"+ TSSimple[x].valor +"}")
                    {
                        temp1 = stoi(TSSimple[x].valor);
                        break;
                    }
                }
            }
            pila[puntero] = "";
            puntero--;
            int temp2;
            try{
                temp2 = stoi(pila[puntero]);
            }catch(std::invalid_argument& e){
                for (int x=0; x<punteroTS; x++)
                {
                    if (pila[puntero] == TSSimple[x].lexema + "{"+ TSSimple[x].valor +"}")
                    {
                        temp2 = stoi(TSSimple[x].valor);
                        break;
                    }
                }
            }
            pila[puntero] = "";
            int resultado;

             __asm__ ( "subl %%ebx, %%eax;"
                    : "=a" (resultado)
                    : "a" (temp2), "b" (temp1) );


            pila[puntero] = std::to_string(resultado);
        }
     	else if (cadena == "mpi")
        {
            int temp1;
            try{
                temp1 = stoi(pila[puntero]);
            }catch(std::invalid_argument& e){
                for (int x=0; x<punteroTS; x++)
                {
                    if (pila[puntero] == TSSimple[x].lexema + "{"+ TSSimple[x].valor +"}")
                    {
                        temp1 = stoi(TSSimple[x].valor);
                        break;
                    }
                }
            }
            pila[puntero] = "";
            puntero--;
            int temp2;
            try{
                temp2 = stoi(pila[puntero]);
            }catch(std::invalid_argument& e){
                for (int x=0; x<punteroTS; x++)
                {
                    if (pila[puntero] == TSSimple[x].lexema + "{"+ TSSimple[x].valor +"}")
                    {
                        temp2 = stoi(TSSimple[x].valor);
                        break;
                    }
                }
            }
            pila[puntero] = "";
            int resultado;

             __asm__ ( "imull %%ebx, %%eax;"
                    : "=a" (resultado)
                    : "a" (temp2), "b" (temp1) );

            pila[puntero] = std::to_string(resultado);

        }

        else if (cadena == "read") //leer valor guardar valor en temporales y dejarlo en la pila
        {

        }
        else if (cadena == "write") // buscar en temporales la variable e imprimir
        {
             fe >> valor;

            for (int x=0; x<punteroTS; x++)
            {
                if (valor == TSSimple[x].lexema)
                {
                        cout << TSSimple[x].valor;  //ensamblador debe de imprimir este valor
                        break;
                }
            }
        }
        else if(cadena=="les"){
            int temp1;
            try{
                temp1 = stoi(pila[puntero]);
            }catch(std::invalid_argument& e){
                for (int x=0; x<punteroTS; x++)
                {
                    if (pila[puntero] == TSSimple[x].lexema + "{"+ TSSimple[x].valor +"}")
                    {
                        temp1 = stoi(TSSimple[x].valor);
                        break;
                    }
                }
            }
            tope = temp1;
            pila[puntero] = "";
            puntero--;
            int temp2;
            try{
                temp2 = stoi(pila[puntero]);
            }catch(std::invalid_argument& e){
                for (int x=0; x<punteroTS; x++)
                {
                    if (pila[puntero] == TSSimple[x].lexema + "{"+ TSSimple[x].valor +"}")
                    {
                        temp2 = stoi(TSSimple[x].valor);
                        break;
                    }
                }
            }
            base = temp2;
            pila[puntero] = "";
            if(ffor){
                pila[puntero]="For " + to_string(base);
                continue;
            }
            if(temp2 < temp1){
                condicion = true;
                pila[puntero] = "True";
            }else
                pila[puntero] = "False";
        }
        else if (cadena == "grt")
        {
           // sacar las tres instruccion y pasarselas a ensamblador para que me regrese el resultado y ponerlo en la pila
           int temp1;
            try{
                temp1 = stoi(pila[puntero]);
            }catch(std::invalid_argument& e){
                for (int x=0; x<punteroTS; x++)
                {
                    if (pila[puntero] == TSSimple[x].lexema + "{"+ TSSimple[x].valor +"}")
                    {
                        temp1 = stoi(TSSimple[x].valor);
                        break;
                    }
                }
            }
            pila[puntero] = "";
            puntero--;
            int temp2;
            try{
                temp2 = stoi(pila[puntero]);
            }catch(std::invalid_argument& e){
                for (int x=0; x<punteroTS; x++)
                {
                    if (pila[puntero] == TSSimple[x].lexema + "{"+ TSSimple[x].valor +"}")
                    {
                        temp2 = stoi(TSSimple[x].valor);
                        break;
                    }
                }
            }
            pila[puntero] = "";
            if(temp2 > temp1){
                condicion = true;
                pila[puntero] = "True";
            }else
                pila[puntero] = "False";

        }
        else if (cadena == "fjp")
        {
            fe >> id;
            label = id;
            if(condicion==false)
                salto=true;
            continue;
            //sacar de la pila el valor bool y si es falto entro en un ciclo hasta encontrar label n y continuar.
        }
        else if(cadena == "cmp"){
            fe >> id;
            cmp = id;
            ffor=true;
        }
        else if (cadena == "ujp"){
            fe >> id;
            label = id;
            ujp=true;
            continue;

        }else if(cadena == "jnz"){
            if(base!=tope-1){
                base++;
                pila[puntero]="For " + to_string(base);
                fe.seekg(0);
                for(int x = 0; x <= contador+1; x++){
                    getline(fe, linea);
                }
            }
            else{
                pila[puntero]="";
                ujp=false;
                ffor=false;
                puntero--;
            }
            continue;
        }
        else if(cadena=="lab"){
            continue;
        }
        else if (cadena==label){
            continue;
        }
        for(int x=0; x < 20; x++)
        {
            cout << "pila[" << x << "]=" << pila[x];
            cout << endl;
        }
        cout << endl;
        if(!ujp)
            contador++;
    }

	fe.close();


	system("pause");
	return 0;
}
