from glumpy import app 

# download glfw and put dll in PATH
app.use('glfw')
window = app.Window()

@window.event 
def on_draw(dt):
  window.clear()

app.run()