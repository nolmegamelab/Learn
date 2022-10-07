from glumpy import app, gloo, gl 

window = app.Window() 

vs = """
  uniform float time; 
  attribute vec2 position; 
  void main() 
  {
    vec2 xy = vec2(sin(2.0*time), cos(2.0*time));
    gl_Position = vec4(position*(0.25 + 0.75*xy*xy), 0.0, 1.0);
  }
"""

fs = """
  uniform vec4 color; 
  void main() 
  {
    gl_FragColor = color;
  }
"""

quad = gloo.Program(vs, fs, count=4) 

quad['position'] = [(-0.5, -0.5),
                    (-0.5, +0.5),
                    (+0.5, -0.5),
                    (+0.5, +0.5)]
quad['color'] = 1,0,0,1  # red

@window.event
def on_draw(dt):
    window.clear()
    quad['time'] += dt
    quad.draw(gl.GL_TRIANGLE_STRIP)

app.run()