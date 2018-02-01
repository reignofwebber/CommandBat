
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "gameroomparameter.h"

using namespace std;

Parameters parameters;

int main(int argc,char** argv)
{
	fstream in("xxx.sql");
	ofstream out("xxx_out.sql");
	ofstream bat("xxx_out.bat");

	string line;
	string curnote;
	while (getline(in, line))
	{
		decltype(line.size()) notpos = line.find("--");
		if (notpos != string::npos)
		{
			curnote = line.substr(2);						//Ãû×Ö
		}

		decltype(line.size()) pos = line.find("VALUES");
		if (pos != string::npos)
		{
			line = line.substr(pos);
			pos = line.find("(");
			if (pos != string::npos)
			{
				GameRoomParameter parameter;
				
				parameter.Note = curnote;

				line = line.substr(pos + 1);			
				//cout << stoi(line,&pos) << endl;
				parameter.ServerID = stoi(line, &pos);	//ServerID

				line = line.substr(pos + 1);			//eat the comma
				pos = line.find(',');
				parameter.ServerName = Tools::ParseSqlString(line.substr(0, pos));	//ServerName

				line = line.substr(pos + 1);
				parameter.KindID = stoi(line, &pos);	//KindID

				line = line.substr(pos + 1);
				parameter.NodeID = stoi(line, &pos);	//NodeID

				line = line.substr(pos + 1);
				parameter.SortID = stoi(line, &pos);	//SortID

				line = line.substr(pos + 1);
				parameter.GameID = stoi(line, &pos);	//GameID

				line = line.substr(pos + 1);
				parameter.TableCount = stoi(line, &pos);		//TableCount

				line = line.substr(pos + 1);
				parameter.ServerKind = stoi(line, &pos);		//ServerKind

				line = line.substr(pos + 1);
				parameter.ServerType = stoi(line, &pos);		//ServerType

				line = line.substr(pos + 1);
				parameter.ServerPort = stoi(line, &pos);		//ServerPort

				line = line.substr(pos + 1);
				parameter.ServerLevel = stoi(line, &pos);		//ServerLevel

				line = line.substr(pos + 1);
				pos = line.find(',');
				parameter.ServerPasswd = Tools::ParseSqlString(line.substr(0, pos));		//ServerPasswd
				
				line = line.substr(pos + 1);
				pos = line.find(',');
				parameter.DataBaseName = Tools::ParseSqlString(line.substr(0, pos));		//DataBaseName

				line = line.substr(pos + 1);
				pos = line.find(',');
				parameter.DataBaseAddr = Tools::ParseSqlString(line.substr(0, pos));		//DataBaseAddr

				line = line.substr(pos + 1);
				parameter.CellScore = stoi(line, &pos);		//CellScore

				line = line.substr(pos + 1);
				parameter.RevenueRatio = stoi(line, &pos);		//RevenueRatio

				line = line.substr(pos + 1);
				parameter.ServiceScore = stoi(line, &pos);			//ServiceScore

				line = line.substr(pos + 1);
				parameter.RestrictScore = stoi(line, &pos);			//RestrictScore

				line = line.substr(pos + 1);
				parameter.MinTableScore = stoi(line, &pos);			//MinTableScore

				line = line.substr(pos + 1);
				parameter.MinEnterScore = stoi(line, &pos);			//MinEnterScore

				line = line.substr(pos + 1);
				parameter.MaxEnterScore = stoi(line, &pos);			//MaxEnterScore

				line = line.substr(pos + 1);
				parameter.MinEnterMember = stoi(line, &pos);			//MinEnterMember

				line = line.substr(pos + 1);
				parameter.MaxEnterMember = stoi(line, &pos);			//MaxEnterMember

				line = line.substr(pos + 1);
				parameter.MaxPlayer = stoi(line, &pos);			//MaxPlayer
				
				line = line.substr(pos + 1);
				parameter.ServerRule = stoi(line, &pos);			//ServerRule
				
				line = line.substr(pos + 1);
				parameter.DistributeRule = stoi(line, &pos);			//DistributeRule

				line = line.substr(pos + 1);
				parameter.MinDistributeUser = stoi(line, &pos);			//MinDistributeUser

				line = line.substr(pos + 1);
				parameter.DistributeTimeSpace = stoi(line, &pos);			//DistributeTimeSpace

				line = line.substr(pos + 1);
				parameter.DistributeDrawCount = stoi(line, &pos);			//DistributeDrawCount

				line = line.substr(pos + 1);
				parameter.MinPartakeGameUser = stoi(line, &pos);			//MinPartakeGameUser

				line = line.substr(pos + 1);
				parameter.MaxPartakeGameUser = stoi(line, &pos);			//MaxPartakeGameUser

				line = line.substr(pos + 1);
				parameter.AttachUserRight = stoi(line, &pos);			//AttachUserRight

				line = line.substr(pos + 1);
				pos = line.find(',');
				parameter.ServiceMachine = Tools::ParseSqlString(line.substr(0, pos));			//ServiceMachine

				line = line.substr(pos + 1);
				pos = line.find(',');
				parameter.CustomRule = Tools::ParseSqlString(line.substr(0, pos));			//CustomRule

				line = line.substr(pos + 1);
				parameter.Nullity = stoi(line, &pos);				//Nullity

				line = line.substr(pos + 1);
				pos = line.find(',');
				parameter.ServerNote = Tools::ParseSqlString(line.substr(0, pos));			//ServerNote

				line = line.substr(pos + 1);
				pos = line.find(',');
				parameter.CreateDateTime = Tools::ParseSqlString(line.substr(0, pos));		//CreateDateTime

				line = line.substr(pos + 1);
				pos = line.find(',');
				parameter.ModifyDateTime = Tools::ParseSqlString(line.substr(0, pos));		//ModifyDateTime

				line = line.substr(pos + 1);
				pos = line.find(')');
				parameter.EnterPassword = Tools::ParseSqlString(line.substr(0, pos));		//EnterPassword

				parameters.push_back(parameter);
				
				if (parameter.ServerType == GOLD_ROOM_TYPE)
				{
					++parameters.m_CurrentSize;
				}
				else
				{
					++parameters.m_CurrentPersonalRoomSize;
				}
			}
		}
	}

	//cout << (*parameters.m_GoldRoomEnd).ServerID << endl;
	//command
	//------------------
	try
	{
		CommandPack commandPack(argc, argv);
		commandPack.PerformCommands();
	}
	catch (...)
	{
		return -1;
	}
	

	Generate(out, parameters);
	GenerateBat(bat, parameters);

	cout << "**************OVER**************" << endl;
	getchar();
	return 0;
}