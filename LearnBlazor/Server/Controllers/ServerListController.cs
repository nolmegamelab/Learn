using LearnBlazor.Shared;
using Microsoft.AspNetCore.Mvc;

namespace LearnBlazor.Server.Controllers
{
	[ApiController]
	[Route("[controller]")]
	public class ServerListController : ControllerBase
	{
		private readonly ILogger<ServerListController> _logger;

		public ServerListController(ILogger<ServerListController> logger)
		{
			_logger = logger;
		}

		[HttpPost]
		public ServerList GetServers(string args)
		{
			var lst = new ServerList();
			lst.Servers.Add(new ServerList.Server() { Address = "127.0.0.1:7000" });
			lst.Servers.Add(new ServerList.Server() { Address = "127.0.0.1:7000" });

			return lst;
		}
	}
}