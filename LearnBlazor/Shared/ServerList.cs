namespace LearnBlazor.Shared
{
	public class ServerList
	{
		public class Server
		{
			public string? Address { get; set; }
		}	

		public List<Server>? Servers { get; private set; }

		public ServerList()
		{
			Servers = new List<Server>();
		}
	}
}