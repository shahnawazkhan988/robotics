# Concept of system of systems and cyber physical systems
<h2>Overview</h2>
<ul>
  <li>Academic Year: 2019-2021</li>
  <li>Project Title: Lab Project on Blockly and Simulation of Kilobots</li>
  <li>Students: Shahnawaz Khan</li>
  <li>CFUs: 9</li>
</ul>
<h2>Requirements:</h2>
<ul>
  <li>A01. There are four Kilobots
  <li>A02. One kilobot is General</li>
  <li>A03. Three kilobot are Lieutenants</li>
  <li>A04. Commands are ATTACK/RETREAT</li>
  <li>A05. Any kilobot can be loyal or traitor</li>
  <li>A06. The initial state is Straight line</li>
  <li>A07. The initial color of light of General is set to Blue</li>
  <li>A08. The initial color of light of three Lieutenants is set to Green</li>
</ul>
<h2>Kilobots Rules:</h2>
<ul>
  <li>B01. In the beginning, all four kilobots are in the straight line.</li>
  <li>B02. The first general pass the message to all three lieutenants and change its color into orange.</li>
  <li>B03. Whenever Lieutenants receive a message from general they change its color into purple.</li>
  <li>B04. First and third Lieutenants are loyal whereas the second lieutenant is traitor.</li>
  <li>B05. General send ATTACK message to all three lieutenant and turn Left.</li>
  <li>B05. Message can be ATTACK/RETREAT.</li>
  <li>B06. First lieutenant sending ATTACK message to the second lieutenant.</li>
  <li>B07. First lieutenant sending ATTACK message to the third lieutenant.</li>
  <li>B08. Second lieutenant sending RETREAT message to the first lieutenant.</li>
  <li>B09. Second lieutenant sending RETREAT message to the third lieutenant.</li>
  <li>B10. Third lieutenant sending ATTACK message to the first lieutenant.</li>
  <li>B11. Third lieutenant sending ATTACK message to the second lieutenant.</li>
  <li>B12. Whenever loyal lieutenant sends a message to other lieutenants the color will be changed into red whereas whenever loyal/traitor lieutenant receives a message the color will be changed into yellow.</li>
  <li>B13. Whenever a traitor lieutenant sends a message to other lieutenants the color will be changed into black whereas whenever loyal lieutenants receive a message the color will be changed into yellow.</li>
  <li>B14. After all communication, the behavior of lieutenant is dependent on majority messages.</li>
  <li>B15. At last, the General will be STOP.</li>
  <li>B16. The final position of Kilobots is; loyal should be red and the traitor should be black that’s how we can identify who is loyal and a traitor.</li>
</ul>
<h2>Design:</h2>
<p>The design of the Byzantine Rule has been done in Blockly4SoS application,
Here are SoS requirements as I mentioned earlier,
Here are SoS system, which names Kilombo and is composed of four systems, which names are General, Lieutenant1, Lieutenant2, Lieutenant3, Lieutenant4.
In all four systems, we mentioned its system type, state space, service, state variable and for communication we used RUMI.
Here General sends an ATTACK message to the other three composed systems of SoS whereas the other three composed systems are received the messages.</p>
