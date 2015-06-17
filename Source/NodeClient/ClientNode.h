namespace Nodes
{
	class ClientNode
	{
		static hAddress serverNode;
		
		static uint32_t sequenceID;
		static std::unordered_map<uint32_t, Network::NetworkPacket*> pendingData;
		static HANDLE sNodeDiscoveryThread;
		static HANDLE sPacketReceiverThread;
		static std::mutex mutex;

		static DWORD _stdcall NodeDiscoverySender(void  *lparam);
		static DWORD _stdcall NodePacketReceiver(void  *lparam);
		
	public:
		static bool isSNodeConnected;

		static bool InitializeNode();
		static Network::NetworkPacket* CreateNetworkPacket(EventType eventType, uint32_t DataLength, void* DataBuffer);
		static uint32_t GetSequence();
		static int32_t GetFriendCount(int32_t iFriendFlags);
		static uint64_t ClientNode::GetFriendByIndex(int32_t iFriend, int32_t iFriendFlags);
	};
}