using Microsoft.AspNetCore.ResponseCompression;
using Serilog.Extensions.Logging.File;
using Microsoft.Extensions.Logging;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.

builder.Services.AddControllersWithViews();
builder.Services.AddRazorPages();
builder.Services.AddSwaggerGen();
builder.Services.AddHttpClient();

builder.Host.ConfigureLogging(logging =>
{
    logging.ClearProviders();
	logging.AddConsole();
});


builder.Logging.AddFile("Logs/LearnBlazor-{Date}.log");

var app = builder.Build();

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
	app.UseWebAssemblyDebugging();
	app.UseSwagger();
	app.UseSwaggerUI();
}
else
{
	app.UseExceptionHandler("/Error");
	// The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.
	app.UseHsts();
}

app.UseHttpsRedirection();

app.UseBlazorFrameworkFiles();
app.UseStaticFiles();

app.UseRouting();


app.MapRazorPages();
app.MapControllers();
app.MapFallbackToFile("index.html");

app.Run();
