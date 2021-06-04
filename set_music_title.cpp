#include <iostream>
#include<string>
#include <fstream>
using namespace std;

// extract name
string music_name;

void remove_site_names()
{
    int x,y,z,xw,yw;
    bool front_mila=false,end_mila=false;
    string:: iterator start=music_name.begin(),End=music_name.begin();
    for(unsigned int i=0;i<music_name.size();i++)
    {
        if(music_name[i]=='.')
        {
            x=i-1;  //current position with '.'
            y=i+1;
            while(!(front_mila && end_mila))
            {
                if((music_name[x]=='(' || music_name[x]=='[' || music_name[x]==' ' || music_name[x]=='_' || x==0 || music_name[x]=='-') && !front_mila)
                {
                    front_mila=true;
                    xw=x;
                }
                else x--;
                if((music_name[y]==')' || music_name[y]==']' || music_name[y]==' ' || music_name[y]=='_' || y==music_name.size()-1 || music_name[y]=='-') && !end_mila)
                {
                    end_mila=true;
                    yw=y;
                }
                else y++;

            }
                advance(start,xw);
                advance(End,yw+1);
                //cout<<"a"<<*start<<"b"<<*End<<"b\n";
                music_name.erase(start,End);
                music_name.insert(xw," ");
                break;
        }
    }

}


void title_filter()
{
   cout << "Hello world!" << endl;
    //to lower case
    for(unsigned int i=0;i<music_name.size();i++)
    {
       music_name[i]=tolower(music_name[i]);
     /*  if(music_name[i]==' ')
        cout<<"a"<<int(music_name[i])<<"b\n";*/
    }

    //removing words with '.' in it
    remove_site_names();
    remove_site_names();

    //removing front shit
    int x=1;
    string:: iterator start=music_name.begin();
    for(unsigned int i=0;i<music_name.size();i++)
    {
        if(music_name[i]>=97 && music_name[i]<=122)
        {
            x=i;
            break;
        }
    }
    music_name[x]=toupper(music_name[x]);
    music_name.erase(start,start+x);


    //replacing - or_ with blank spaces
    for(unsigned int i=0;i<music_name.size();i++)
    {
        if(music_name[i]=='%' && music_name[i+1]=='2' && music_name[i+2]=='0')
        {
            music_name[i]=' ';
            music_name.erase(i+1,i+3);
            i=i+2;
        }
        if(music_name[i]=='-' || music_name[i]=='_' || music_name[i]=='\\' || music_name[i]=='/' || music_name[i]=='%')
        {
            music_name[i]=' ';
        }
    }

    //removing integers or kbps or mp3 or any other standard string
    string s3="320kbps",s1="128kbps",s3_i="320",s1_i="128",s_kbps="kbps",s_mp3="mp3",s_64="64",s_190="190";
    string::iterator ptr,temp;
    for(ptr=music_name.begin();ptr<music_name.end();ptr++)
    {
        if(*ptr=='3')
        {
            string m_s3=string(ptr,ptr+7);
            string m_s3_i=string(ptr,ptr+3);
            if(!m_s3.compare(s3))
            {
                music_name.erase(ptr,ptr+7);
                music_name.insert(ptr,' ');
            }
            else
                {
                    if(!m_s3_i.compare(s3_i))
                    {
                        music_name.erase(ptr,ptr+3);
                        music_name.insert(ptr,' ');
                    }
                }
        }
        if(*ptr=='1')
        {
            string m_s1=string(ptr,ptr+7);
            string m_s1_i=string(ptr,ptr+3);

            string m_s_190=string(ptr,ptr+3);
            if(!m_s_190.compare(s_190))
            {
                music_name.erase(ptr,ptr+3);
                music_name.insert(ptr,' ');
            }

            if(!m_s1.compare(s1))
            {
                music_name.erase(ptr,ptr+7);
                music_name.insert(ptr,' ');
            }
            else
                {
                    if(!m_s1_i.compare(s1_i))
                    {
                        music_name.erase(ptr,ptr+3);
                        music_name.insert(ptr,' ');
                    }
                }
        }
        if(*ptr=='0')
        {
            music_name.erase(ptr,ptr+2);
            music_name.insert(ptr,' ');
        }
        if(*ptr=='k')
        {
            string m_s_kbps=string(ptr,ptr+4);
            if(!m_s_kbps.compare(s_kbps))
            {
                music_name.erase(ptr,ptr+4);
                music_name.insert(ptr,' ');
            }
        }
        if(*ptr=='m')
        {
            string m_s_mp3=string(ptr,ptr+3);
            if(!m_s_mp3.compare(s_mp3))
            {
                music_name.erase(ptr,ptr+3);
                music_name.insert(ptr,' ');
            }
        }
        if(*ptr=='6')
        {
            string m_s_64=string(ptr,ptr+2);
            if(!m_s_64.compare(s_64))
            {
                music_name.erase(ptr,ptr+2);
                music_name.insert(ptr,' ');
            }
        }

    }


    //Camel Case and removing extra spacing
    bool space_mila=false;
    string::iterator temp_it,end_space;
    for(ptr=music_name.begin();ptr<music_name.end();ptr++)
    {
        if(*ptr==' ')
        {
            space_mila=true;
            //start_space=ptr;
            //cout<<*(ptr-1)<<"\n";
            temp_it=ptr;
            while(space_mila)
            {
                    temp_it++;
                    if(*temp_it!=' ' || temp_it==music_name.end())
                    {
                        //cout<<*temp_it<<"\n";
                        end_space=temp_it;
                        space_mila=false;
                    }

            }

            music_name.erase(ptr,end_space);
            if(ptr!=music_name.end())
            {
                *ptr=toupper(*ptr);
                music_name.insert(ptr,' ');
            }
        }

    }


    //removing empty brackets
    string s_bracket_space1="[]",s_bracket_space2="()",s_bracket_space3="[ ]",s_bracket_space4="( )";
    for(ptr=music_name.begin();ptr<music_name.end();ptr++)
    {
        if(*ptr=='(')
        {
            string m_s_bracket_space2=string(ptr,ptr+2);
            string m_s_bracket_space4=string(ptr,ptr+3);
            if(!m_s_bracket_space2.compare(s_bracket_space2))
            {
                music_name.erase(ptr,ptr+2);
                music_name.insert(ptr,' ');
            }

            if(!m_s_bracket_space4.compare(s_bracket_space4))
            {
                music_name.erase(ptr,ptr+3);
                music_name.insert(ptr,' ');
            }
        }

        if(*ptr=='[')
        {
            string m_s_bracket_space1=string(ptr,ptr+2);
            string m_s_bracket_space3=string(ptr,ptr+3);
            if(!m_s_bracket_space1.compare(s_bracket_space1))
            {
                music_name.erase(ptr,ptr+2);
                music_name.insert(ptr,' ');
            }

            if(!m_s_bracket_space3.compare(s_bracket_space3))
            {
                music_name.erase(ptr,ptr+3);
                music_name.insert(ptr,' ');
            }
        }

    }



    //Removing extra spacing one last time
    space_mila=false;
    for(ptr=music_name.begin();ptr<music_name.end();ptr++)
    {
        if(*ptr==' ')
        {
            space_mila=true;
            //start_space=ptr;
            //cout<<*(ptr-1)<<"\n";
            temp_it=ptr;
            while(space_mila)
            {
                    temp_it++;
                    if(*temp_it!=' ' || temp_it==music_name.end())
                    {
                        //cout<<*temp_it<<"\n";
                        end_space=temp_it;
                        space_mila=false;
                    }

            }

            music_name.erase(ptr,end_space);
            if(ptr!=music_name.end())
            {
                music_name.insert(ptr,' ');
            }
        }

    }

}



int main()
{
  ofstream file2,clear_file1;
  file2.open ("All_names_after_c++.txt");

  ifstream file1;
  string line;
  file1.open ("All_original_names.txt");
    while ( getline (file1,music_name) )
    {
        title_filter();
        file2 <<music_name<< "\n";
    }

  file1.close();
  /*clear_file1.open("All_original_names.txt",ofstream::out|ofstream::trunc);
  clear_file1.close();*/
  file2.close();


    return 0;
}
