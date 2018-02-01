#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>

#define GOLD_ROOM_SERVERID_START				0
#define PERSONAL_ROOM_SERVERID_START			1600

#define ADDITIONAL_ROOM_SERVERID_START			1700

#define GOLD_ROOM_TYPE							1
#define PERSONAL_ROOM_TYPE						16


#define GOLD_ROOM_SERVERPORT_START				9000
#define PERSONAL_ROOM_SERVERPORT_START			9200

#define ADDITIONAL_ROOM_SERVERPORT_START		9300

#define GOLD_ROOM_COUNT							4


static const std::vector<std::string> s_DefaultServerName = { "新手场","地主场","土豪场","神豪场" };


struct GameRoomParameter
{

	std::string Note;
	bool IsRem;

	int ServerID;
	std::string ServerName;
	int KindID;
	int NodeID;
	int SortID;
	int GameID;
	
	int TableCount;
	int ServerKind;
	int ServerType;
	int ServerPort;
	int ServerLevel;

	std::string ServerPasswd;
	std::string DataBaseName;
	std::string DataBaseAddr;

	long long CellScore;
	short RevenueRatio;
	long long ServiceScore;
	long long RestrictScore;
	long long MinTableScore;
	long long MinEnterScore;
	long long MaxEnterScore;
	
	int MinEnterMember;
	int MaxEnterMember;
	int MaxPlayer;
	int ServerRule;

	int DistributeRule;
	int MinDistributeUser;
	int DistributeTimeSpace;
	int DistributeDrawCount;
	int MinPartakeGameUser;
	int MaxPartakeGameUser;
	int AttachUserRight;

	std::string ServiceMachine;
	std::string CustomRule;

	short Nullity;
	std::string ServerNote;
	std::string CreateDateTime;
	std::string ModifyDateTime;
	std::string EnterPassword;

	GameRoomParameter()
	{
		IsRem = false;
		Note = "";
		ServerID = 0;
		ServerName = "";
		KindID = 0;
		NodeID = 0;
		SortID = 0;
		GameID = 0;
		TableCount = 60;
		ServerKind = 1;
		ServerType = 1;
		ServerPort = 0;
		ServerLevel = 0;

		ServerPasswd = "";
		DataBaseName = "RYTreasureDB";
		DataBaseAddr = "127.0.0.1";
		CellScore = 0;
		RevenueRatio = 0;
		ServiceScore = 0;
		RestrictScore = 0;
		MinTableScore = 0;
		MinEnterScore = 0;
		MaxEnterScore = 0;

		MinEnterMember = 0;
		MaxEnterMember = 0;
		MaxPlayer = 0;
		ServerRule = 0;				//sdsd

		DistributeRule = 0;
		MinDistributeUser = 0;
		DistributeTimeSpace = 0;
		DistributeDrawCount = 0;
		MinPartakeGameUser = 0;
		MaxPartakeGameUser = 0;
		AttachUserRight = 0;

		ServiceMachine = "";
		CustomRule = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

		Nullity = 0;
		ServerNote = "";
		CreateDateTime = "CAST(0x0000A82C01027C32 AS DateTime)";
		ModifyDateTime = "CAST(0x0000A82C01027C32 AS DateTime)";
		EnterPassword = "";

	}

};

struct Parameters
{
	std::vector<GameRoomParameter> m_parameters;
	size_t m_CurrentSize;
	size_t m_CurrentPersonalRoomSize;
	size_t m_CurrentAdditionalRoomSize;


	void push_back(GameRoomParameter const & parameter)
	{
		m_parameters.push_back(parameter);
	}
	decltype(m_parameters.begin()) begin()
	{
		return m_parameters.begin();
	}
	decltype(m_parameters.cbegin()) cbegin()
	{
		return m_parameters.cbegin();
	}
	decltype(m_parameters.end()) end()
	{
		return m_parameters.end();
	}
	decltype(m_parameters.cend()) cend()
	{
		return m_parameters.cend();
	}
	void insert(std::vector<GameRoomParameter>::iterator iter,const GameRoomParameter & parameter)
	{
		m_parameters.insert(iter, parameter);
	}
	GameRoomParameter &operator[](size_t i)
	{
		return m_parameters[i];
	}
	
};

extern Parameters parameters;

class Tools
{
public:
	static std::string ParseSqlString(std::string sqlstring)
	{
		auto pos = sqlstring.find('\'');
		sqlstring = sqlstring.substr(pos + 1);
		pos = sqlstring.find('\'');
		sqlstring = sqlstring.substr(0, pos);
		return sqlstring;
	}
	static std::vector<std::string> Split(std::string paramstring)
	{
		std::vector<std::string> params;
		
		decltype(paramstring.size()) pos;
		while ((pos = paramstring.find(",")) != std::string::npos)
		{
			std::string param = paramstring.substr(0, pos);
			paramstring = paramstring.substr(pos + 1);
			params.push_back(param);
		}
		params.push_back(paramstring);
		return params;
	}
};

class Command
{
public:
	static void RenameServerName(short level, std::string const & name)
	{
		if (level == GOLD_ROOM_COUNT) level = 0;
		for_each(parameters.begin(), parameters.end(), [&](GameRoomParameter& parameter) {
			if (parameter.ServerID > PERSONAL_ROOM_SERVERID_START) return;
			if (parameter.ServerID % GOLD_ROOM_COUNT == level)
			{
				parameter.ServerName = name;
			}
		});
	}
	static void RenameServerName(std::string const & server, short level, std::string const & name)
	{
		if (level == GOLD_ROOM_COUNT) level = 0;
		for (auto iter = parameters.begin(); iter != parameters.begin() + parameters.m_CurrentSize; ++iter)
		{
			if (server == (*iter).Note && ((*iter).ServerID % GOLD_ROOM_COUNT == level))
			{
				(*iter).ServerName = name;
				break;
			}
		}
	}
	static void AddServer(int id, std::string const & name)
	{
		for (int i = 0; i < GOLD_ROOM_COUNT; ++i)
		{
			++parameters.m_CurrentSize;
			GameRoomParameter parameter;
			parameter.Note = name;
			parameter.ServerID = parameter.SortID = parameters.m_CurrentSize + GOLD_ROOM_SERVERID_START;
			parameter.KindID = parameter.GameID = id;
			parameter.ServerPort = parameters.m_CurrentSize + GOLD_ROOM_SERVERPORT_START;
			parameter.ServerName = s_DefaultServerName[i];
			parameters.insert(parameters.begin() + (parameters.m_CurrentSize - 1), parameter);
			
		}
		
	}
	static void AddAdditionalServer(std::string const & servername, size_t size = 1)
	{
		GameRoomParameter templateParameter;
		size_t i = 0;
		while (parameters[i].ServerID < PERSONAL_ROOM_SERVERID_START)
		{
			if (parameters[i].Note == servername)
			{
				templateParameter = parameters[i];
				break;
			}
			++i;
		}

		for (size_t i = 0; i < size; ++i)
		{
			++parameters.m_CurrentAdditionalRoomSize;
			GameRoomParameter parameter(templateParameter);
			parameter.ServerID = parameters.m_CurrentAdditionalRoomSize + ADDITIONAL_ROOM_SERVERID_START;
			parameter.ServerPort = parameters.m_CurrentAdditionalRoomSize + ADDITIONAL_ROOM_SERVERPORT_START;
			parameter.SortID = parameter.ServerID;
			parameters.push_back(parameter);
		}
	}

	static void RemServer(std::string const & name, std::vector<int> const & servers)
	{

	}
};

class CommandPack
{

public:
	CommandPack(int argc, char** argv)
	{
		if (!(argc % 2))
		{
			std::cout << "参数格式不正确！" << std::endl;
			throw -1;
		}

		for (int i = 1; i < argc; ++i)
		{
			if (i % 2)
			{
				m_commands.push_back(argv[i]);
			}
			else
			{
				m_params.push_back(argv[i]);
			}
		}

	}
	CommandPack(std::vector<std::string> commands,std::vector<std::string> params)
		:m_commands(commands),m_params(params){}

	void PerformCommands()
	{
		for (size_t i = 0; i < Size(); ++i)
		{
			if (m_commands[i] == "-r1")
			{
				Command::RenameServerName(1,m_params[i]);
			}
			else if (m_commands[i] == "-r2") 
			{
				Command::RenameServerName(2, m_params[i]);
			}
			else if (m_commands[i] == "-r3")
			{
				Command::RenameServerName(3, m_params[i]);
			}
			else if (m_commands[i] == "-r4")
			{
				Command::RenameServerName(4, m_params[i]);
			}
			else if (m_commands[i] == "-add")
			{
				std::vector<std::string> params = Tools::Split(m_params[i]);
				if (params.size() != 2) throw - 1;
				Command::AddServer(stoi(params[0]), params[1]);
			}
			else if (m_commands[i] == "-rem")
			{
				std::vector<std::string> params = Tools::Split(m_params[i]);
				if (params.size() < 2 || params.size() > 1 + GOLD_ROOM_COUNT) throw - 1;
				std::vector<int> servers;
				std::for_each(params.cbegin()+1, params.cend(), [&](std::string const & param) {
					servers.push_back(stoi(param));
				});
				Command::RemServer(params[0],servers);

			}
			else if (m_commands[i] == "-r")
			{
				std::vector<std::string> params = Tools::Split(m_params[i]);
				if (params.size() != 3) throw - 1;
				Command::RenameServerName(params[0], stoi(params[1]), params[2]);
			}
			else if (m_commands[i] == "-addroom")
			{
				std::string param = m_params[i];
				Command::AddAdditionalServer(param);
			}
		}
	}

	std::vector<std::string>::size_type Size()
	{
		return m_commands.size();
	}

protected:
	std::vector<std::string> m_commands;
	std::vector<std::string> m_params;
};




void GeneratePre(std::ofstream& out)
{
	out << "USE RYPlatformDB" << std::endl;
	out << "GO\n" << std::endl;

	out << "TRUNCATE TABLE [dbo].[GameRoomInfo]" << std::endl;

	out << "SET IDENTITY_INSERT [dbo].[GameRoomInfo] ON\n" << std::endl;
}

void GeneratePost(std::ofstream& out)
{
	out << std::endl;
	out << "SET IDENTITY_INSERT [dbo].[GameRoomInfo] OFF" << std::endl;
}

void GenerateInsert(std::ofstream& out, GameRoomParameter const & parameter)
{
	static int remcount = 0;
	if (parameter.ServerID > 1600)
	{
		out << "--" << parameter.Note << std::endl;
	}
	else
	{
		if (!(remcount % GOLD_ROOM_COUNT)) {
			out << "--" << parameter.Note << std::endl;
		}
		++remcount;
	}
	

	out << "INSERT [dbo].[GameRoomInfo] ([ServerID], [ServerName], [KindID], [NodeID], [SortID], [GameID], [TableCount], [ServerKind], [ServerType], [ServerPort], [ServerLevel], [ServerPasswd], [DataBaseName], [DataBaseAddr], [CellScore], [RevenueRatio], [ServiceScore], [RestrictScore], [MinTableScore], [MinEnterScore], [MaxEnterScore], [MinEnterMember], [MaxEnterMember], [MaxPlayer], [ServerRule], [DistributeRule], [MinDistributeUser], [DistributeTimeSpace], [DistributeDrawCount], [MinPartakeGameUser], [MaxPartakeGameUser], [AttachUserRight], [ServiceMachine], [CustomRule], [Nullity], [ServerNote], [CreateDateTime], [ModifyDateTime], [EnterPassword]) VALUES"
		<< "("
		<< parameter.ServerID << ","
		<< "N'" + parameter.ServerName + "'" << ","
		<< parameter.KindID << ","
		<< parameter.NodeID << ","
		<< parameter.SortID << ","
		<< parameter.GameID << ","
		<< parameter.TableCount << ","
		<< parameter.ServerKind << ","
		<< parameter.ServerType << ","
		<< parameter.ServerPort << ","
		<< parameter.ServerLevel << ","
		<< "N'" + parameter.ServerPasswd + "'" << ","
		<< "N'" + parameter.DataBaseName + "'" << ","
		<< "N'" + parameter.DataBaseAddr + "'" << ","
		<< parameter.CellScore << ","
		<< parameter.RevenueRatio << ","
		<< parameter.ServiceScore << ","
		<< parameter.RestrictScore << ","
		<< parameter.MinTableScore << ","
		<< parameter.MinEnterScore << ","
		<< parameter.MaxEnterScore << ","
		<< parameter.MinEnterMember << ","
		<< parameter.MaxEnterMember << ","
		<< parameter.MaxPlayer << ","
		<< parameter.ServerRule << ","
		<< parameter.DistributeRule << ","
		<< parameter.MinDistributeUser << ","
		<< parameter.DistributeTimeSpace << ","
		<< parameter.DistributeDrawCount << ","
		<< parameter.MinPartakeGameUser << ","
		<< parameter.MaxPartakeGameUser << ","
		<< parameter.AttachUserRight << ","
		<< "N'" + parameter.ServiceMachine + "'" << ","
		<< "N'" + parameter.CustomRule + "'" << ","
		<< parameter.Nullity << ","
		<< "N'" + parameter.ServerNote + "'" << ","
		<< parameter.CreateDateTime << ","
		<< parameter.ModifyDateTime << ","
		<< "N'" + parameter.EnterPassword + "'" << ")"
		<< std::endl;
}

void Generate(std::ofstream& out,Parameters & parameters)
{
	GeneratePre(out);
	for_each(parameters.cbegin(), parameters.cend(), [&](GameRoomParameter const & parameter) {
		GenerateInsert(out, parameter);
	});

	GeneratePost(out);

}

void GenerateBat(std::ofstream& bat, Parameters & parameters)
{
	for_each(parameters.cbegin(), parameters.cend(), [&](GameRoomParameter const & parameter)
	{
		static int remcount = 0;
		if (parameter.ServerID > 1600)
		{
			bat << "REM " << parameter.Note << std::endl;
		}
		else
		{
			if (!(remcount % GOLD_ROOM_COUNT)) {
				bat << "REM " << parameter.Note << std::endl;
			}
			++remcount;
		}
		bat << "start GameServer.exe /ServerID:" << parameter.ServerID << std::endl;
	});
}
