#pragma oncee

#include "defines.h"

class CGlobalVarsBase
{
public:
	// Absolute time (per frame still - Use Plat_FloatTime() for a high precision real time 
	//  perf clock, but not that it doesn't obey host_timescale/host_framerate)
	float realTime;
	// Absolute frame counter - continues to increase even if game is paused
	int frameCount;
	// Non-paused frametime
	float absoluteFrameTime;
	float absoluteFrameTimeStdDev;

	// Current time 
	//
	// On the client, this (along with tickcount) takes a different meaning based on what
	// piece of code you're in:
	// 
	//   - While receiving network packets (like in PreDataUpdate/PostDataUpdate and proxies),
	//     this is set to the SERVER TICKCOUNT for that packet. There is no interval between
	//     the server ticks.
	//     [server_current_Tick * tick_interval]
	//
	//   - While rendering, this is the exact client clock 
	//     [client_current_tick * tick_interval + interpolation_amount]
	//
	//   - During prediction, this is based on the client's current tick:
	//     [client_current_tick * tick_interval]
	float curTime;

	// Time spent on last server or client frame (has nothing to do with think intervals)
	float frameTime;
	// current maxplayers setting
	int maxClients;

	// Simulation ticks - does not increase when game is paused
	int tickCount;

	// Simulation tick interval
	float intervalPerTick;

	int networkProtocol;

	// current saverestore data
	CSaveRestoreData* saveData;

	// Set to true in client code.
	bool client;

	// true if we are a remote client (needs prediction & interpolation - server not on this machine) as opposed to split-screen or local
	bool remoteClient;

	/*
	private:
	// 100 (i.e., tickcount is rounded down to this base and then the "delta" from this base is networked
	int				nTimestampNetworkingBase;
	// 32 (entindex() % nTimestampRandomizeWindow ) is subtracted from gpGlobals->tickcount to set the networking basis, prevents
	//  all of the entities from forcing a new PackedEntity on the same tick (i.e., prevents them from getting lockstepped on this)
	int				nTimestampRandomizeWindow;
	*/
};
