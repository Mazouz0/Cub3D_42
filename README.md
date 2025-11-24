<!-- Paste this into your README.md -->
<div style="max-width:900px;margin:18px auto;padding:20px;border-radius:12px;font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, 'Helvetica Neue', Arial;line-height:1.5;color:#24292e;border:1px solid rgba(27,31,35,0.08);background:linear-gradient(180deg, #ffffff 0%, #fbfbfc 100%);box-shadow:0 6px 18px rgba(99,102,241,0.06)">

  <h1 style="margin:0 0 6px;font-size:28px;display:flex;align-items:center;gap:10px">
    <span style="font-size:26px">🐚</span>
    Minishell
  </h1>
  <p style="margin:0 0 16px;color:#57606a">
    A minimal Unix-like shell written in C for the 42 School curriculum — implements basic bash behavior: parsing, execution, redirections, pipes, and built-ins while following the project's constraints on memory, signals, and processes.
  </p>

  <section style="margin-bottom:14px">
    <h2 style="font-size:18px;margin:8px 0">✨ Features</h2>
    <ul style="margin:6px 0 0 20px">
      <li>Interactive prompt using <code>readline</code></li>
      <li>Robust command parsing supporting quotes, expansions, and tokenization</li>
      <li>Pipes and pipelines (<code>|</code>)</li>
      <li>Redirections: <code>&lt;</code>, <code>&gt;</code>, <code>&gt;&gt;</code>, heredoc <code>&lt;&lt;</code></li>
      <li>Environment variable expansion (<code>$VAR</code>)</li>
      <li>Built-in commands: <code>echo</code>, <code>cd</code>, <code>pwd</code>, <code>export</code>, <code>unset</code>, <code>env</code>, <code>exit</code></li>
      <li>External program execution using <code>execve</code></li>
      <li>Signal handling for <code>Ctrl+C</code>, <code>Ctrl+D</code>, and <code>Ctrl+\</code></li>
      <li>Aim: zero memory leaks after each command</li>
    </ul>
  </section>

  <section style="margin-bottom:14px">
    <h2 style="font-size:18px;margin:8px 0">🛠️ Goals</h2>
    <p style="margin:6px 0 0 0;color:#57606a">
      Build a compact, stable shell to learn how real shells work: process creation and termination, I/O and file descriptor manipulation, pipe mechanics, heredocs, and robust signal handling.
    </p>
  </section>

  <section style="margin-bottom:14px">
    <h2 style="font-size:18px;margin:8px 0">🚀 Quick start</h2>
    <pre style="background:#f6f8fa;border-radius:8px;padding:12px;overflow:auto;margin:8px 0"><code>make
./minishell
</code></pre>
    <p style="margin:6px 0 0;color:#57606a">Type commands like in a normal shell. Use built-ins or execute programs available in <code>/bin</code> and <code>/usr/bin</code>.</p>
  </section>


</div>
