using LearnBlazor.Shared;
using Microsoft.AspNetCore.Mvc;

namespace LearnBlazor.Server.Controllers
{
	[ApiController]
	[Route("[controller]")]
	public class ServerConfigController : ControllerBase
	{
		private readonly ILogger<ServerListController> _logger;

		public ServerConfigController(ILogger<ServerListController> logger)
		{
			_logger = logger;
		}

		[HttpPost]
		public ServerList SaveConfig([FromBody] ServerList.Server server)
		{
			var lst = new ServerList();
			lst.Servers.Add(new ServerList.Server() { Address = "127.0.0.1:7000" });
			lst.Servers.Add(new ServerList.Server() { Address = "127.0.0.1:8000" });

			// TODO: Save to json file
			lst.Servers.Add(server);

			return lst;
		}
	}
}