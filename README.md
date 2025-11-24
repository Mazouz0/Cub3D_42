<div style="max-width:900px;margin:20px auto;padding:24px;border-radius:14px;font-family:-apple-system,BlinkMacSystemFont,'Segoe UI',Roboto,'Helvetica Neue',Arial;line-height:1.55;color:#24292e;border:1px solid #e1e4e8;background:#ffffff">

  <h1 style="font-size:28px;margin:0 0 10px">
    🎮 cub3D
  </h1>

  <p style="margin:0 0 16px;color:#57606a">
    <strong>cub3D</strong> is a 42 graphics project where you create a basic 3D engine using raycasting, similar to the classic Wolfenstein 3D.  
    You work with angles, rays, textures, math, and the MLX42 library to render a first-person view inside a 2D map.
  </p>

  <h2 style="font-size:20px;margin:20px 0 8px">✨ Main Features</h2>
  <ul>
    <li>Real-time raycasting engine</li>
    <li>Loading and rendering wall textures</li>
    <li>Player movement + rotation using angles</li>
    <li>Correct wall projection with distance correction</li>
    <li>Keyboard input, window handling through MLX42</li>
    <li>Collision detection</li>
    <li>Parsing and validating the <code>.cub</code> map file</li>
  </ul>

  <h2 style="font-size:20px;margin:20px 0 8px">📐 Raycasting Explained</h2>
  <p style="color:#57606a">
    Raycasting converts a 2D map into a 3D world by sending one ray for each vertical line on the screen.
    Each ray:
  </p>

  <ul>
    <li>Has its own angle inside the player’s Field of View (usually 60°)</li>
    <li>Moves forward step-by-step until hitting a wall</li>
    <li>Calculates distance to that wall</li>
    <li>Uses projection math to determine wall height</li>
    <li>Uses cosine correction to avoid the fish-eye effect</li>
  </ul>

  <pre style="background:#f6f8fa;padding:12px;border-radius:8px;overflow:auto">
height = (TILE_SIZE / distance) * projection_plane_distance
  </pre>

  <p style="color:#57606a">
    This creates the illusion of 3D depth while being extremely fast and simple.
  </p>

  <h2 style="font-size:20px;margin:20px 0 8px">🎨 Textures</h2>
  <p style="color:#57606a">
    Each wall direction (North, South, East, West) has its own texture.  
    After a ray hits the wall, the engine computes:
  </p>

  <ul>
    <li>The side of the wall hit (N/S/E/W)</li>
    <li>The exact hit position on the wall</li>
    <li>The X offset to sample from the texture</li>
    <li>The Y progression while drawing the vertical slice</li>
  </ul>

  <h2 style="font-size:20px;margin:20px 0 8px">📁 Map (.cub File)</h2>
  <ul>
    <li>Texture paths (NO, SO, WE, EA)</li>
    <li>Floor and ceiling colors</li>
    <li>The 2D map made of 1s and 0s</li>
    <li>Player start position and orientation</li>
  </ul>

  <p style="color:#57606a">
    The map is validated to ensure it is closed and contains only valid characters.
  </p>

  <h2 style="font-size:20px;margin:20px 0 8px">🎮 Controls</h2>
  <ul>
    <li><strong>W / S</strong> — Move forward / backward</li>
    <li><strong>A / D</strong> — Strafe left / right</li>
    <li><strong>← / →</strong> — Rotate the camera</li>
    <li><strong>ESC</strong> — Quit</li>
  </ul>

  <h2 style="font-size:20px;margin:20px 0 8px">🚀 Build & Run</h2>
  <pre style="background:#f6f8fa;padding:12px;border-radius:8px;overflow:auto">
make
./cub3D maps/map.cub
  </pre>

  <h2 style="font-size:20px;margin:20px 0 8px">📚 Project Goals</h2>
  <ul>
    <li>Understand raycasting and projection</li>
    <li>Use trigonometry for movement and angles</li>
    <li>Manipulate pixels and textures at low level</li>
    <li>Learn event handling with MLX42</li>
    <li>Write clean, modular C graphics code</li>
  </ul>


</div>
