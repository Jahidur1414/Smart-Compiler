/*
    Author : Jahidur Rahman (v - 0.7---Final)

    Smart Compiler !!
*/
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <ostream>
#include <fstream>
#include <map>

using namespace std;

map<string, int> mp;

void cloutput() //eha only output file tare saf korbo
{
    std::ofstream ofs;
    ofs.open("output.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

void cltemp() //eha only temporary file tare saf korbo
{
    std::ofstream ofs;
    ofs.open("temp.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}
void clinput() // eha only output file tare saf korbo
{
    std::ofstream ofs;
    ofs.open("input.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

void addnewline()// ehon lagbo na magar final code e lagbo
{
    FILE *temp;
    char ff[2];
    ff[0]=' ';
    ff[1]='\0';
    temp=fopen("temp.txt", "a");
    fprintf(temp, "%s\n", ff);
    fclose(temp);
    ff[0]='}';
    ff[1]='\0';
    temp=fopen("temp.txt", "a");
    fprintf(temp, "%s\n", ff);
    fclose(temp);
}
void addsecondbreket()//eha soource  code er last e ekta semicolon lagai dibo
{
    FILE *output;
    char ff[2];
    ff[0]='}';
    ff[1]='\0';
    output=fopen("output.txt", "a");
    fprintf(output, "%s\n", ff);
    fclose(output);
}
void write() //eha input neyar jonno ( joto khusi toto neya jaibo input)
{
    FILE *input;
    FILE *output;

    while(1)
    {
        char code[1000];
        gets(code);

        if(strcasecmp(code, "Save")==0)
        {
            break;
        }
        input=fopen("input.txt", "a");
        fprintf(input, "%s\n", code);
        fclose(input);
    }

    cout<<"That's All "<<endl;
}

void printmp()
{
    map<string,int>::const_iterator it;

    cout<<"All variable name and their values "<<endl;

    for (it = mp.begin(); it!= mp.end(); it++)
    {

        cout << it->first<<" = "<< it->second<<endl;
    }
}

void fahim(char str[])
{
    //cout<<"Line --- "<<str<<endl;
    //cout<<str<<endl;

    string name;
    string number;
    string tm;
    for(int i=0; i<=strlen(str); i++)
    {
        if(str[i]==' ' || str[i]=='\0' || str[i]==',' || str[i]==';')
        {
            int dk=0;
            for(int x=0; x<=tm.size(); x++)
            {
                if(tm[x]=='=')
                {
                    dk=1;
                    break;
                }
            }

            if(dk==1)
            {
                int p=0;
                for(int j=0; tm[j]!='='; j++)
                {
                    name+=tm[j];
                    p=j;
                }
                for(int j=p+2; j<=tm.size(); j++)
                {
                    number+=tm[j];
                }


                //cout<<"Name ---- "<<name<<endl;
                stringstream geek(number);
                int num = 0;
                geek >> num;
                //cout<<"Number ---- "<<num<<endl;

                mp[name]=num;
            }

            name.clear();
            number.clear();
            tm.clear();
        }
        else
        {
            tm+=str[i];
        }
    }
}
void symboltable()
{
    FILE *output;
    FILE *temp;
    cltemp();
    char ch;
    string str;
    string fs;
    fs.clear();
    output = fopen("output.txt", "r");

    while((ch = fgetc(output))!=EOF)
    {
        if(ch=='\n')
        {
            //cout<<str<<endl;
            string blb;
            int dk=0, sp=0;

            //cout<<str.size()<<endl;

            for(int j=0; j<str.size(); j++)
            {
                if(str[j]==' ')
                {
                    sp++;
                }
            }

            if(sp==str.size())
            {
                dk=1;
                //cout<<"New line detect !! "<<endl;
            }
            if(dk==0)
            {
                for(int i=0; i<=str.size(); i++)
                {
                    if(str[i]==' ' || str[i]=='\0' || str[i]=='(' || str[i]==')' || str[i]==';' || str[i]=='|' || str[i]=='&')
                    {
                        //cout<<blb<<endl;

                        int st=0, l=blb.size();
                        for(int t=0; t<blb.size(); t++)
                        {
                            if(blb[t]!=' ')
                            {
                                //cout<<"Starting --- "<<blb[t]<<endl;
                                st=t;
                                break;
                            }
                        }

                        if(blb[st]=='f' && blb[l-1]=='r') //for
                        {
                            dk=1;
                            //cout<<"For Detect !!!"<<endl;
                            blb.clear();
                            break;
                        }
                        else if(blb[st]=='i' && blb[l-1]=='f') //if
                        {
                            dk=1;
                            //cout<<"If Detect !!!"<<endl;
                            blb.clear();
                            break;
                        }
                        else if(blb[st]=='e' && blb[l-1]=='e') //else
                        {
                            dk=1;
                            //cout<<"Else Detect !!!"<<endl;
                            blb.clear();
                            break;
                        }
                        else if(blb[st]=='m' && blb[l-1]=='n') //main()
                        {
                            dk=1;
                            //cout<<"Main Detect !!!"<<endl;
                            blb.clear();
                            break;
                        }
                        else if(blb[st]=='w' && blb[l-1]=='e') //while
                        {
                            dk=1;
                            //cout<<"While Detect !!!"<<endl;
                            blb.clear();
                            break;
                        }
                        else if(blb[st]=='#') //#
                        {
                            dk=1;
                            //cout<<"While Detect !!!"<<endl;
                            blb.clear();
                            break;
                        }
                        else if(blb[st]=='{' || blb[st]=='}') // brackets
                        {
                            dk=1;
                            //cout<<"Brackets Detect !!!"<<endl;
                            blb.clear();
                            break;
                        }
                        blb.clear();
                    }
                    else
                    {
                        blb+=str[i];
                    }
                }
            }

            if(dk==1) // Normal line na
            {
                int h=1;
            }
            else if(dk==0) // Normal line
            {
                char f[1000];
                int s=0;
                for(int g=0; g<str.size(); g++)
                {
                    f[s++]=str[g];
                }
                f[s]='\0';
                fahim(f);
                for(int g=0; g<str.size(); g++)
                {
                    f[g]='\0';
                }
            }
            fs.clear();
            str.clear();
        }
        else
        {
            str+=ch;
        }
    }
    fclose(output);
}
void delcom() //eha comment soray
{
    FILE *input;
    FILE *output;
    char ch;
    int cnt = 0, block = 0, line = 0;
    input = fopen("input.txt","r");
    output = fopen("output.txt", "w");
    while ((ch = fgetc(input)) != EOF)
    {
        if (cnt == 0 && ch == '/')
        {
            cnt++;
            continue;
        }
        else if (cnt && ch == '*')
            block = 1;
        else if (cnt && ch == '/')
            line = 1;
        else if (cnt && !block && !line)
        {
            fputc('/', output);
            fputc(ch, output);
            cnt = 0;
            continue;
        }
        if (block)
            if (ch == '*' && fgetc(input) == '/')
            {
                block = 0, cnt = 0;
                continue;
            }
        if (line)
        {
            if (ch == '\n')
                line = 0, cnt = 0;
        }
        if (!block && !line)
            fputc(ch, output);
    }
    fclose(input);
    fclose(output);
}

void linker() // 11 gonta lagse eitare fix korte so eitare tuch kora haram
{
    FILE *output;
    FILE *temp;
    cltemp();
    char ch;
    string str;
    output = fopen("output.txt", "r");

    string gf;
    while((ch = fgetc(output))!=EOF)
    {
        if(ch=='\n')
        {
            //mela
            //cout<<str<<endl;
            string s;
            for(int i=0; i<=str.size(); i++)
            {
                if(str[i]==' ' || str[i]=='\0' || str[i]=='(')
                {
                    //cout<<s<<endl;
                    int l=s.size(), st=0;
                    for(int q=0; q<s.size(); q++)
                    {
                        if(s[q]==' ')
                        {
                            gf+=s[q];
                        }
                        else
                        {
                            st=q;
                            //cout<<"Starting ----"<<s[q]<<endl; // word er soro ta kojar jonno use kora hoise
                            break;
                        }
                    }
                    if((s[st]=='m' || s[st]=='M') && (s[l-1]=='n' || s[l-1]=='N'))
                    {
                        //cout<<"Paisi"<<endl;
                        gf+="main";
                        s.clear();
                        gf+=str[i];
                    }
                    else if((s[st]=='i' || s[st]=='I') && (s[l-1]=='t' || s[l-1]=='T'))
                    {
                        gf+="int";
                        s.clear();
                        gf+=str[i];
                    }
                    else if((s[st]=='w' || s[st]=='W') && (s[l-1]=='e' || s[l-1]=='e'))
                    {
                        gf+="while";
                        s.clear();
                        gf+=str[i];
                    }
                    else if((s[st]=='f' || s[st]=='F') && (s[l-1]=='r' || s[l-1]=='R'))
                    {
                        gf+="for";
                        s.clear();
                        gf+=str[i];
                    }
                    else if((s[st]=='p' || s[st]=='P') && (s[l-1]=='f' || s[l-1]=='F'))
                    {
                        gf+="printf";
                        s.clear();
                        gf+=str[i];
                    }
                    else if((s[st]=='s' || s[st]=='S') && (s[l-1]=='f' || s[l-1]=='F'))
                    {
                        gf+="scanf";
                        s.clear();
                        gf+=str[i];
                    }
                    else if((s[st]=='i' || s[st]=='I') && (s[l-1]=='f' || s[l-1]=='F'))
                    {
                        gf+="if";
                        s.clear();
                        gf+=str[i];
                    }
                    else if((s[st]=='e' || s[st]=='E') && (s[l-1]=='e' || s[l-1]=='E'))
                    {
                        gf+="else";
                        s.clear();
                        gf+=str[i];
                    }
                    else if(s[st]=='#' && s[1]=='i')
                    {
                        gf+="#include";
                        s.clear();
                        gf+=str[i];
                    }
                    else
                    {
                        gf+=s;//word ta gf e add kor
                        s.clear();
                        //s+=str[i];
                        if(str[i]==' ')
                        {
                            gf+=str[i];
                        }
                    }
                    /*if(str[i]!=' ')
                    {
                        s+=str[i];
                    }*/
                }
                else
                {
                    s+=str[i];
                }
            }
            str.clear();

            //cout<<gf<<endl;// ene gf tare temp e dokamo

            char pera[1000];
            int k=0;
            for(int j=0; j<gf.size(); j++)
            {
                pera[k++]=gf[j];
            }
            pera[k]='\0';

            //temp e dokamo pera string array tare
            temp=fopen("temp.txt", "a");
            fprintf(temp, "%s\n", pera);
            fclose(temp);

            for(int j=0; j<gf.size(); j++)
            {
                pera[j]='\0';
            }

            gf.clear();
        }
        else
        {
            str+=ch;
        }
    }
    fclose(output);

    cloutput();


    char ch1;
    string str3;
    temp = fopen("temp.txt", "r");
    while ((ch1 = fgetc(temp)) != EOF)
    {
        if(ch1=='\n')
        {
            //cout<<str<<endl;
            char er [10000];
            int e=0;
            for(int a=0; a<str3.size(); a++)
            {
                er[e++]=str3[a];
            }
            er[e]='\0';
            output=fopen("output.txt", "a");
            fprintf(output, "%s\n", er);
            fclose(output);
            for(int a=0; a<str3.size(); a++)
            {
                er[a]='\0';
            }
            str3.clear();
        }
        else
        {
            str3+=ch1;
        }
    }
    //addsecondbreket();
    fclose(temp);
}

int pera(char c)
{
    if(c=='=' || c=='>' || c=='<' || c=='!')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void logicalsatement_and_Construct() // eha Logical statement error and Construct written wrong kajer jonno banano hoise !!!
{
    cltemp();
    FILE *output;
    FILE *temp;
    cltemp();
    char ch;
    string str;
    output = fopen("output.txt", "r");

    string ttc;
    while((ch = fgetc(output))!=EOF)
    {
        int chk=0;
        if(ch=='\n')
        {
            //cout<<str<<endl;
            // ene add kormo mela kahinir golpo ( Thakur mar juli )!!!!

            string f;
            for(int i=0; i<=str.size(); i++)
            {
                if(str[i]==' ' || str[i]=='\0' || str[i]=='(' || str[i]==')' || str[i]==';' || str[i]=='|' || str[i]=='&')
                {
                    //cout<<"Target word ---- "<<ttc<<endl;// target word

                    int st=0, l=ttc.size();
                    for(int q=0; q<ttc.size(); q++)
                    {
                        if(ttc[q]==' ')
                        {
                            f+=ttc[q];
                        }
                        else
                        {
                            st=q;
                            //cout<<"Starting ----"<<s[q]<<endl; // word er soro ta kojar jonno use kora hoise
                            break;
                        }
                    }

                    if(ttc[st]=='f' && ttc[l-1]=='r')// for
                    {
                        chk=2;
                    }
                    else if(ttc[st]=='i' && ttc[l-1]=='f')// if
                    {
                        chk=1;
                    }
                    else if(ttc[st]=='w' && ttc[l-1]=='e')// while
                    {
                        chk=1;
                    }

                    if(chk==1)
                    {
                        //mela kaj !! target word niya
                        //cout<<"Paisi mama !!!"<<endl;

                        int con=1;

                        for(int a=st; a<ttc.size(); a++)
                        {
                            //f+=ttc[a];

                            if(pera(ttc[a]))
                            {
                                //kaj hobe !!
                                if(ttc[a]==ttc[a-1])
                                {
                                    con++;
                                }

                                if(con<=2)
                                {
                                    f+=ttc[a];
                                }
                                else
                                {
                                    continue;
                                }
                            }
                            else
                            {
                                f+=ttc[a];
                            }

                        }
                    }
                    else if(chk==2)
                    {
                        for(int a=st; a<ttc.size(); a++)
                        {
                            //f+=ttc[a];
                            if(pera(ttc[a]))
                            {
                                //kaj hobe !!
                                if(ttc[a]==ttc[a-1])
                                {
                                    continue;
                                }
                                else
                                {
                                    f+=ttc[a];
                                }
                            }
                            else
                            {
                                f+=ttc[a];
                            }

                        }
                    }
                    else
                    {
                        for(int j=st; j<ttc.size(); j++)
                        {
                            f+=ttc[j]; // target line sara gula add kormo final sentence e !
                        }
                    }

                    //f+=ttc; // final word tare final sentence e add kormo
                    ttc.clear();
                    f+=str[i];// add breaking point sate in final sentence
                }
                else
                {
                    ttc+=str[i];
                }
            }

            //cout<<"Final sentence "<<f<<endl; //Final sentence (add korbo temp file e )

            char fkk[10000];
            int t=0;
            for(int s=0; s<f.size(); s++)
            {
                fkk[t++]=f[s];
            }
            fkk[t]='\0';
            temp=fopen("temp.txt", "a");
            fprintf(temp, "%s\n", fkk);
            fclose(temp);
            for(int s=0; s<f.size(); s++)
            {
                fkk[s]='\0';
            }

            f.clear();//clear kora lagbo next sentence er jonno
            str.clear();//clear sentence catching container for next work
        }
        else
        {
            str+=ch;
        }

    }

    fclose(output);
    cloutput();


    char ch4;
    string str4;
    temp = fopen("temp.txt", "r");
    while ((ch4 = fgetc(temp)) != EOF)
    {
        if(ch4=='\n')
        {
            //cout<<str<<endl;
            char er[10000];
            int e=0;
            for(int a=0; a<str4.size(); a++)
            {
                er[e++]=str4[a];
            }
            er[e]='\0';
            output=fopen("output.txt", "a");
            fprintf(output, "%s\n", er);
            fclose(output);
            for(int a=0; a<str4.size(); a++)
            {
                er[a]='\0';
            }
            str4.clear();
        }
        else
        {
            str4+=ch4;
        }
    }
    //addsecondbreket();
    fclose(temp);
}
void addsemi()
{
    char jala[2];
    jala[0]=';';
    jala[1]='\0';
    FILE *temp;
    temp=fopen("temp.txt", "a");
    fprintf(temp, "%s\n", jala);
    fclose(temp);

}
void missingsemicolon() // Missing semicolon
{
    cltemp();
    FILE *output;
    FILE *temp;
    cltemp();
    char ch;
    string str;
    string fs;
    fs.clear();
    output = fopen("output.txt", "r");

    while((ch = fgetc(output))!=EOF)
    {
        if(ch=='\n')
        {
            //cout<<str<<endl;
            string blb;
            int dk=0, sp=0;

            //cout<<str.size()<<endl;

            for(int j=0; j<str.size(); j++)
            {
                if(str[j]==' ')
                {
                    sp++;
                }
            }

            if(sp==str.size())
            {
                dk=1;
                //cout<<"New line detect !! "<<endl;
            }
            if(dk==0)
            {
                for(int i=0; i<=str.size(); i++)
                {
                    if(str[i]==' ' || str[i]=='\0' || str[i]=='(' || str[i]==')' || str[i]==';' || str[i]=='|' || str[i]=='&')
                    {
                        //cout<<blb<<endl;

                        int st=0, l=blb.size();
                        for(int t=0; t<blb.size(); t++)
                        {
                            if(blb[t]!=' ')
                            {
                                //cout<<"Starting --- "<<blb[t]<<endl;
                                st=t;
                                break;
                            }
                        }

                        if(blb[st]=='f' && blb[l-1]=='r') //for
                        {
                            dk=1;
                            //cout<<"For Detect !!!"<<endl;
                            blb.clear();
                            break;
                        }
                        else if(blb[st]=='i' && blb[l-1]=='f') //if
                        {
                            dk=1;
                            //cout<<"If Detect !!!"<<endl;
                            blb.clear();
                            break;
                        }
                        else if(blb[st]=='e' && blb[l-1]=='e') //else
                        {
                            dk=1;
                            //cout<<"Else Detect !!!"<<endl;
                            blb.clear();
                            break;
                        }
                        else if(blb[st]=='m' && blb[l-1]=='n') //main()
                        {
                            dk=1;
                            //cout<<"Main Detect !!!"<<endl;
                            blb.clear();
                            break;
                        }
                        else if(blb[st]=='w' && blb[l-1]=='e') //while
                        {
                            dk=1;
                            //cout<<"While Detect !!!"<<endl;
                            blb.clear();
                            break;
                        }
                        else if(blb[st]=='#') //#
                        {
                            dk=1;
                            //cout<<"While Detect !!!"<<endl;
                            blb.clear();
                            break;
                        }
                        else if(blb[st]=='{' || blb[st]=='}') // brackets
                        {
                            dk=1;
                            //cout<<"Brackets Detect !!!"<<endl;
                            blb.clear();
                            break;
                        }
                        blb.clear();
                    }
                    else
                    {
                        blb+=str[i];
                    }
                }
            }

            if(dk==1) // Normal line na
            {
                for(int g=0; g<str.size(); g++)
                {
                    fs+=str[g];
                }
            }
            else if(dk==0) // Normal line
            {
                for(int g=0; g<str.size(); g++)
                {
                    if(str[g]==';')
                    {
                        continue;
                    }
                    else
                    {
                        fs+=str[g];
                    }
                }
                fs+=' ;';
            }

            //cout<<"Final sentence -- "<<fs<<endl; // ei sentence tare anar jonno almost laptop vangtesilam !!

            char fkk[10000];
            int t=0;
            for(int s=0; s<fs.size(); s++)
            {
                fkk[t++]=fs[s];
            }
            fkk[t]='\0';
            temp=fopen("temp.txt", "a");
            fprintf(temp, "%s\n", fkk);
            fclose(temp);
            for(int s=0; s<fs.size(); s++)
            {
                fkk[s]='\0';
            }
            fs.clear();
            str.clear();
        }
        else
        {
            str+=ch;
        }
    }
    fclose(output);

    cloutput();

    char ch6;
    string str6;
    temp = fopen("temp.txt", "r");
    while ((ch6 = fgetc(temp)) != EOF)
    {
        if(ch6=='\n')
        {
            //cout<<str<<endl;
            char er[10000];
            int e=0;
            for(int a=0; a<str6.size(); a++)
            {
                er[e++]=str6[a];
            }
            er[e]='\0';
            output=fopen("output.txt", "a");
            fprintf(output, "%s\n", er);
            fclose(output);
            for(int a=0; a<str6.size(); a++)
            {
                er[a]='\0';
            }
            str6.clear();
        }
        else
        {
            str6+=ch6;
        }
    }
    //addsecondbreket();
    fclose(temp);

}

void runtimeps() // RunTime ......................great work pronb ......................
{
    cltemp();
    FILE *output;
    FILE *temp;
    char ch;
    int a;
    string str;
    output = fopen("output.txt", "r");
    stack<char> sf;
    sf.empty();
    char x;
    while ((ch = fgetc(output)) != EOF)
    {
        if(ch=='\n')
        {
            //cout<<str<<endl;
            //n++;
            string car;
            for(int i=0; i<str.size(); i++)
            {
                if(str[i]=='/' )
                {
                    if( str[i-1]!='0' && str[i+1]=='0')
                    {
                        str[i+1]='1';


                        car+=str[i];
                        continue;
                    }


                }


                else
                {
                    car+=str[i];
                }
            }

            char fk[1000];
            int r=0, ck=0;
            for(int s=0; s<car.size(); s++)
            {
                fk[r++]=car[s];

            }
            fk[r]='\0';
            temp=fopen("temp.txt", "a");
            fprintf(temp, "%s\n", fk);
            fclose(temp);
            car.clear();
            str.clear();
            for(int k=0; k<car.size(); k++)
            {
                fk[k]='\0';
            }
        }
        else
        {
            str+=ch;
        }
    }
    fclose(output);

    cloutput();


    char ch1;
    string str3;
    temp = fopen("temp.txt", "r");
    while ((ch1 = fgetc(temp)) != EOF)
    {
        if(ch1=='\n')
        {
            //cout<<str<<endl;
            char er[10000];
            int e=0;
            for(int a=0; a<str3.size(); a++)
            {
                er[e++]=str3[a];
            }
            er[e]='\0';
            output=fopen("output.txt", "a");
            fprintf(output, "%s\n", er);
            fclose(output);
            for(int a=0; a<str3.size(); a++)
            {
                er[a]='\0';
            }
            str3.clear();
        }
        else
        {
            str3+=ch1;
        }
    }
    //addsecondbreket();

    fclose(temp);
}

void fixdpera() //eha parameter thik kore ( volew ei function bojar try koris na or hat dis na... onek genjam salarta ! onek koste create korsi !)
{
    FILE *output;
    FILE *temp;
    char ch;
    string str;
    output = fopen("output.txt", "r");
    stack<char> sf;
    sf.empty();
    char x;

    while ((ch = fgetc(output)) != EOF)
    {
        if(ch=='\n')
        {
            //cout<<str<<endl;
            //n++;
            string car;
            for(int i=0; i<str.size(); i++)
            {
                if(str[i]=='(' || str[i]=='[' || str[i]=='{')
                {
                    sf.push(str[i]);
                    car+=str[i];
                    continue;
                }
                else if(str[i]==')' || str[i]==']' || str[i]=='}')
                {
                    if(sf.empty())
                    {
                        continue;
                    }
                    else
                    {
                        switch(str[i])
                        {
                        case ')':
                            x = sf.top();
                            sf.pop();
                            if(x=='{')
                            {
                                //Ene ekta new line dokaite hobe
                                //addnewline();

                                car+=' ';
                            }
                            else if(x=='[')
                            {
                                car+=']';
                            }
                            else
                            {
                                car+=str[i];
                            }
                            break;

                        case '}':
                            x = sf.top();
                            sf.pop();
                            if(x=='(')
                            {
                                car+=')';
                            }
                            else if(x=='[')
                            {
                                car+=']';
                            }
                            else
                            {
                                car+=str[i];
                            }
                            break;

                        case ']':
                            x = sf.top();
                            sf.pop();
                            if(x=='(')
                            {
                                car+=')';
                            }
                            else if(x=='{')
                            {
                                car+=' ';
                            }
                            else
                            {
                                car+=str[i];
                            }
                            break;
                        default:
                            car+=str[i];
                            break;
                        }
                    }
                }
                else
                {
                    car+=str[i];
                }
            }

            char fk[1000];
            int r=0, ck=0;
            for(int s=0; s<car.size(); s++)
            {
                fk[r++]=car[s];

            }
            fk[r]='\0';
            temp=fopen("temp.txt", "a");
            fprintf(temp, "%s\n", fk);
            fclose(temp);
            car.clear();
            str.clear();
            for(int k=0; k<car.size(); k++)
            {
                fk[k]='\0';
            }
        }
        else
        {
            str+=ch;
        }
    }
    fclose(output);

    cloutput();


    char ch1;
    string str3;
    temp = fopen("temp.txt", "r");
    while ((ch1 = fgetc(temp)) != EOF)
    {
        if(ch1=='\n')
        {
            //cout<<str<<endl;
            char er[10000];
            int e=0;
            for(int a=0; a<str3.size(); a++)
            {
                er[e++]=str3[a];
            }
            er[e]='\0';
            output=fopen("output.txt", "a");
            fprintf(output, "%s\n", er);
            fclose(output);
            for(int a=0; a<str3.size(); a++)
            {
                er[a]='\0';
            }
            str3.clear();
        }
        else
        {
            str3+=ch1;
        }
    }
    //addsecondbreket();
    fclose(temp);
}
void dis()
{
    FILE *output;
    char ch;
    string str;
    output = fopen("output.txt", "r");
    while ((ch = fgetc(output)) != EOF)
    {
        if(ch=='\n')
        {
            cout<<str<<endl;
            str.clear();
        }
        else
        {
            str+=ch;
        }
    }
    fclose(output);
}
void clean()
{
    std::ofstream ofs;
    ofs.open("input.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    ofs.open("output.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    ofs.open("temp.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    mp.clear();
}
int main()
{
    int n=1;


    while(1)
    {
        cout<<"--------------------- ( SMART COMPILER ) ---------------------"<<endl;
        cout<<"Please write your full code and write ( 'Save' ) after complete writing "<<endl;

        write();

        cout<<"--------Thanks----------"<<endl;
        system("cls");

        //------------------- Add all function --------------------
        delcom(); //For delete comment

        fixdpera(); //For perameter
        cltemp();

        linker(); //For linker

        logicalsatement_and_Construct(); // For logical statement

        missingsemicolon(); //for missing Semicolon

        runtimeps(); // For Runtime

        symboltable(); //For symbol table

        cout<<"______________Your Final Right Code_____________"<<endl;
        cout<<endl;
        dis();

        printmp();


        //------------------Exit or Continue part------------------------

        int t;
        cout<<"Enter ('Exit') for Exit Or Enter ('Con') for Continue...... "<<endl;
        char jk[10];
        gets(jk);
        if(strcasecmp(jk, "Exit")==0)
        {
            clean();
            system("cls");
            cout<<"----------------  Thank You ----------------"<<endl;
            break;
        }
        else if(strcasecmp(jk, "Con")==0)
        {
            clean();
            system("cls");
        }
        else
        {
            cout<<"________________ Wrong Input ! _______________"<<endl;
            break;
        }
    }
    return 0;
}
