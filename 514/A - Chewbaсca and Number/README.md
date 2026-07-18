<h2><a href="https://codeforces.com/contest/514/problem/A" target="_blank" rel="noopener noreferrer">514A — Chewbaсca and Number</a></h2>

| | |
|---|---|
| **Difficulty** | 1200 |
| **Language** | C++17 (GCC 7-32) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 514A](https://codeforces.com/contest/514/problem/A) |

## Topics
`greedy` `implementation`

---

## Problem Statement

<div class="header"><div class="title">A. Chewbaсca and Number</div><div class="time-limit"><div class="property-title">time limit per test</div>1 second</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard" style="font-weight: bold"><div class="property-title">input</div>stdin</div><div class="output-file output-standard" style="font-weight: bold"><div class="property-title">output</div>stdout</div></div><div><p>Luke Skywalker gave Chewbacca an integer number <span class="tex-span"><i>x</i></span>. Chewbacca isn't good at numbers but he loves inverting digits in them. Inverting digit <span class="tex-span"><i>t</i></span> means replacing it with digit <span class="tex-span">9 - <i>t</i></span>. </p><p>Help Chewbacca to transform the initial number <span class="tex-span"><i>x</i></span> to the minimum possible <span class="tex-font-style-bf">positive</span> number by inverting some (possibly, zero) digits. The decimal representation of the final number shouldn't start with a zero.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains a single integer <span class="tex-span"><i>x</i></span> <span class="tex-span">(1 ≤ <i>x</i> ≤ 10<sup class="upper-index">18</sup>)</span> — the number that Luke Skywalker gave to Chewbacca.</p></div><div class="output-specification"><div class="section-title">Output</div><p>Print the minimum possible positive number that Chewbacca can obtain after inverting some digits. The number shouldn't contain leading zeroes.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id002754700939451812" id="id00851899564280294" class="input-output-copier">Copy</div></div><pre id="id002754700939451812">27<br></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id001995168778260049" id="id0045544219230739735" class="input-output-copier">Copy</div></div><pre id="id001995168778260049">22<br></pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id006009654742003081" id="id005746100763088363" class="input-output-copier">Copy</div></div><pre id="id006009654742003081">4545<br></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id005251430855443456" id="id007573230478842521" class="input-output-copier">Copy</div></div><pre id="id005251430855443456">4444<br></pre></div></div></div>