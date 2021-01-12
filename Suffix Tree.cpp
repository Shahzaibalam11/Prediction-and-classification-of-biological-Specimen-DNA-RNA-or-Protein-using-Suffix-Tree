#include<iostream>
#include<fstream>
#include<queue>
using namespace std;

class STNode{
	public:
		char data;
		STNode* Character[26];
		STNode()	
		{
			data=-1;
			for(int i=0;i<26;i++)
			{
				Character[i]=NULL;
			}
		}
		STNode(char ch)	
		{
			data=ch;
	    	for(int i=0;i<26;i++)
			{
				Character[i]=NULL;
			}
		}	
};

class STree{
	STNode* root;
	public:
		STree()
		{
			root=NULL;
		}
		void Insert(string s,int n)
		{
			int j=0;
			root=new STNode();
			STNode* p;
			while(j!=n)
			{
				p=root;
				for(int i=j;i<n;i++)
				{
					char ch='A';
					for(int k=0;k<26;k++)
					{
				    if(s[i]==ch)
				    {
				 	if(p->Character[k]==NULL)
				 	p->Character[k]=new STNode(s[i]);
				 	p=p->Character[k];
				    }
					ch++;
					}
				
				}
				j++;
			}
		}
		void preorder(STNode * p)
		{
			if(p!=NULL)
			{
				cout<<p->data<<" ";
				for(int i=0;i<26;i++)
				{
				preorder(p->Character[i]);
			}	
			    
			}
		}
		STNode* getroot()
		{
			return(root);
		}
    void deleteall(STNode* n)
    {
    	if(n==NULL)
    	return;
    	queue<STNode*> q;
    	STNode* p;
    	q.push(n);
    	while(!q.empty())
    	{
    		p=q.front();
    		q.pop();
    		for(int i=0;i<26;i++)
    		{
    		if(p->Character[i])
    		q.push(p->Character[i]);
    	}
    		
    		
    		delete p;
		}
	}
		void setroot()
		{
			root=NULL;
		}
		int Search(STNode* p,string test,int n)
		{
			int i=0;
			bool check=false;
			while(p!=NULL && i!=n)
			{
				if(check==true)
				break;
				char ch='A';
				for(int k=0;k<26;k++)
				{
					if(test[i]==ch)
				{
					if(p->Character[k])
					{
						p=p->Character[k];
						i++;
					}
					else
					{
						check=true;
					}
					if(check==true)
					break;
				}
				ch++;
				}	
			}
		return(i);
		}
		~STree()
		{
			this->deleteall(root);
			root=NULL;
		}
};


int main()
{
	string structureId,chainId,sequence,Test_Specimen,tempID,tempchain,temp,tempSequence;
	int residueCount,percentage;
	ifstream infile("Sequences.txt");
	ofstream outfile("Matched ID's.txt");
	STree s;
	cout<<"Enter your Protein Sequence : ";
	cin>>Test_Specimen;
	int NoOfMatchs,MaxNoOfMatchs=0;
	cout<<"Loading..."<<endl;
	for(int i=0;i<100000;i++)
	{
	infile>>structureId>>chainId>>sequence>>residueCount;
	s.Insert(sequence,sequence.length());
	STNode* p=s.getroot();
	NoOfMatchs=s.Search(p,Test_Specimen,Test_Specimen.length());
	if(NoOfMatchs>=MaxNoOfMatchs)
	{
		if(MaxNoOfMatchs!=0)
	{
		if(NoOfMatchs==Test_Specimen.length())
		{
			percentage=(NoOfMatchs*100)/sequence.length();
			outfile<<structureId<<endl<<percentage<<endl;
		}
	}
		tempID=structureId;
		tempchain=chainId;
		MaxNoOfMatchs=NoOfMatchs;
		tempSequence=sequence;
	}
	s.deleteall(p);
	s.setroot();
	}
	infile.close();
	outfile<<tempID<<endl;
	outfile<<(MaxNoOfMatchs*100)/tempSequence.length()<<endl;
	outfile.close();
	system("cls");
	cout<<"Your Sequence : "<<Test_Specimen<<endl<<endl;
	structureId="-1";
    ifstream i("Matched ID's.txt");
    outfile.open("Result.txt");
    i>>structureId;
    if(structureId.length()==0 || structureId=="-1" )
    {
    	cout<<"The given specimen doesn't match to any Biological compound(DNA/RNA/Protein)"<<endl;
    	outfile<<"The given specimen doesn't match to any Biological compound(DNA/RNA/Protein)"<<endl;
    	
	}
	else
	{
		i.close();
		i.open("Matched ID's.txt");
   while(i>>structureId>>percentage)
   {    
    infile.open("Classification.txt");
    while(!infile.eof())
	{
		infile>>temp;
		if(temp==structureId)
	{
	cout<<"The given specimen is "<<percentage<<"% similar to this Biological compound(DNA/RNA/Protein)"<<endl;
	outfile<<"The given specimen is "<<percentage<<"% similar to this Biological compound(DNA/RNA/Protein)"<<endl;
	cout<<"structureId : "<<temp<<endl;
	outfile<<"structureId : "<<temp<<endl;
	infile>>temp;
	if(temp=="0")
	temp="Not Available";
	cout<<"classification : "<<temp<<endl;
	outfile<<"classification : "<<temp<<endl;
	infile>>temp;
	if(temp=="0")
	temp="Not Available";
	cout<<"experimental Technique : "<<temp<<endl;
	outfile<<"experimental Technique : "<<temp<<endl;
	infile>>temp;
	if(temp=="0")
	temp="Not Available";
	cout<<"macromolecule Type : "<<temp<<endl;
	outfile<<"macromolecule Type : "<<temp<<endl;
	infile>>temp;
	if(temp=="0")
	temp="Not Available";
	cout<<"residue Count : "<<temp<<endl;
	outfile<<"residue Count : "<<temp<<endl;
	infile>>temp;
	if(temp=="0")
	temp="Not Available";	
	cout<<"resolution : "<<temp<<endl;
	outfile<<"resolution : "<<temp<<endl;
	infile>>temp;
	if(temp=="0")
	temp="Not Available";	
	cout<<"structure Molecular Weight : "<<temp<<endl;
	outfile<<"structure Molecular Weight : "<<temp<<endl;
	infile>>temp;
	if(temp=="0")
	temp="Not Available";	
	cout<<"crystallization Method : "<<temp<<endl;
	outfile<<"crystallization Method : "<<temp<<endl;
	infile>>temp;
	if(temp=="0")
	temp="Not Available";	
	cout<<"crystallization TempK : "<<temp<<endl;
	outfile<<"crystallization TempK : "<<temp<<endl;
	infile>>temp;
	if(temp=="0")
	temp="Not Available";	
	cout<<"density Matthews : "<<temp<<endl;
	outfile<<"density Matthews : "<<temp<<endl;
	infile>>temp;
	if(temp=="0")
	temp="Not Available";	
	cout<<"density PercentSol : "<<temp<<endl;
	outfile<<"density PercentSol : "<<temp<<endl;	
	infile>>temp;
	if(temp=="0")
	temp="Not Available";	
	cout<<"pdb xDetails : "<<temp<<endl;
	outfile<<"pdbx Details : "<<temp<<endl;
	infile>>temp;
	if(temp=="0")
	temp="Not Available";	
	cout<<"ph Value : "<<temp<<endl;
	outfile<<"ph Value : "<<temp<<endl;
	infile>>temp;
	if(temp=="0")
	temp="Not Available";	
	cout<<"publication Year : "<<temp<<endl;
	outfile<<"publication Year : "<<temp<<endl;
	break;
    }
        else
        {
        	while(temp!="-1")
        	{
        		infile>>temp;
			}
		}
    }
    infile.close();
    cout<<endl;
    outfile<<endl;
}
}
    i.close();
    outfile.close();
	return(0);
}
