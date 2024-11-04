/*
**  /!\ This file is generated with the script `scripts/main.py`
**  Do NOT manually modify or create files in the `generated/` folder.
**  Prefer re-running the script: `python main.py`
**  ex:
**
**       $> python main.py
**
**  Copyright 2024 Pierre-Nicolas "Ark'Anoryn" Sormani <arkanoryn@gmail.com>
**  SPDX-License-Identifier: GPL-2.0-or-later
**
*/

#include <string.h>

char *check_chord(char *buffer) {
  if (strcmp("\bing ", buffer) == 0) { return "I+N+G"; }
  if (strcmp("\bn't ", buffer) == 0) { return "N+'+T"; }
  if (strcmp("\b've ", buffer) == 0) { return "'+V+E"; }
  if (strcmp("\b're ", buffer) == 0) { return "'+R+E"; }
  if (strcmp("\b's ", buffer) == 0) { return "'+S+MAGIC"; }
  if (strcmp("\b'd ", buffer) == 0) { return "'+D+MAGIC"; }
  if (strcmp("\b'll ", buffer) == 0) { return "'+L+MAGIC"; }
  if (strcmp("a ", buffer) == 0) { return "MAGIC+A"; }
  if (strcmp("A ", buffer) == 0) { return "BSPC+A"; }
  if (strcmp("about ", buffer) == 0) { return "MAGIC+U+T"; }
  if (strcmp("after ", buffer) == 0) { return "F+T+R"; }
  if (strcmp("all ", buffer) == 0) { return "MAGIC+A+L"; }
  if (strcmp("also ", buffer) == 0) { return "A+L+S"; }
  if (strcmp("and ", buffer) == 0) { return "A+N+D"; }
  if (strcmp("any ", buffer) == 0) { return "A+N+Y"; }
  if (strcmp("as ", buffer) == 0) { return "A+S"; }
  if (strcmp("at ", buffer) == 0) { return "A+T"; }
  if (strcmp("back ", buffer) == 0) { return "B+C+K"; }
  if (strcmp("be ", buffer) == 0) { return "B+E"; }
  if (strcmp("because ", buffer) == 0) { return "B+C+E"; }
  if (strcmp("before ", buffer) == 0) { return "B+F+O"; }
  if (strcmp("birthday ", buffer) == 0) { return "B+D+A"; }
  if (strcmp(", but ", buffer) == 0) { return "B+T"; }
  if (strcmp("by ", buffer) == 0) { return "B+Y"; }
  if (strcmp("can ", buffer) == 0) { return "C+A+N"; }
  if (strcmp("can not ", buffer) == 0) { return "C+A+N+T"; }
  if (strcmp("come ", buffer) == 0) { return "C+M+E"; }
  if (strcmp("could ", buffer) == 0) { return "C+O+U"; }
  if (strcmp("day ", buffer) == 0) { return "MAGIC+D+A"; }
  if (strcmp("do ", buffer) == 0) { return "MAGIC+D+O"; }
  if (strcmp("even ", buffer) == 0) { return "E+V+N"; }
  if (strcmp("find ", buffer) == 0) { return "F+N+D"; }
  if (strcmp("first ", buffer) == 0) { return "F+I+R"; }
  if (strcmp("for ", buffer) == 0) { return "F+O+R"; }
  if (strcmp("from ", buffer) == 0) { return "F+R+M"; }
  if (strcmp("get ", buffer) == 0) { return "G+E+T"; }
  if (strcmp("give ", buffer) == 0) { return "G+I+E"; }
  if (strcmp("go ", buffer) == 0) { return "MAGIC+G+O"; }
  if (strcmp("great ", buffer) == 0) { return "G+R+E"; }
  if (strcmp("have ", buffer) == 0) { return "H+V+E"; }
  if (strcmp("he ", buffer) == 0) { return "H+E"; }
  if (strcmp("I ", buffer) == 0) { return "I+MAGIC"; }
  if (strcmp("if ", buffer) == 0) { return "I+F"; }
  if (strcmp("in ", buffer) == 0) { return "I+N"; }
  if (strcmp("into ", buffer) == 0) { return "I+N+T"; }
  if (strcmp("it ", buffer) == 0) { return "I+T"; }
  if (strcmp("know ", buffer) == 0) { return "K+N+W"; }
  if (strcmp("knowledge ", buffer) == 0) { return "K+N+W+L"; }
  if (strcmp("like ", buffer) == 0) { return "L+K+E"; }
  if (strcmp("long ", buffer) == 0) { return "L+N+G"; }
  if (strcmp("look ", buffer) == 0) { return "MAGIC+L+K"; }
  if (strcmp("make ", buffer) == 0) { return "M+K+E"; }
  if (strcmp("man ", buffer) == 0) { return "M+A+N"; }
  if (strcmp("many ", buffer) == 0) { return "M+A+N"; }
  if (strcmp("may ", buffer) == 0) { return "M+A+Y"; }
  if (strcmp("more ", buffer) == 0) { return "M+R+E"; }
  if (strcmp("most ", buffer) == 0) { return "M+O+S"; }
  if (strcmp("must ", buffer) == 0) { return "U+S+T"; }
  if (strcmp("new ", buffer) == 0) { return "N+E+W"; }
  if (strcmp("no ", buffer) == 0) { return "N+MAGIC"; }
  if (strcmp("not ", buffer) == 0) { return "N+O+T"; }
  if (strcmp("now ", buffer) == 0) { return "N+O+W"; }
  if (strcmp("of ", buffer) == 0) { return "O+F"; }
  if (strcmp("on ", buffer) == 0) { return "O+N"; }
  if (strcmp("one ", buffer) == 0) { return "O+N+E"; }
  if (strcmp("only ", buffer) == 0) { return "O+L+Y"; }
  if (strcmp("or ", buffer) == 0) { return "MAGIC+O+R"; }
  if (strcmp("other ", buffer) == 0) { return "O+T+R"; }
  if (strcmp("out ", buffer) == 0) { return "O+U+T"; }
  if (strcmp("over ", buffer) == 0) { return "O+V+E"; }
  if (strcmp("say ", buffer) == 0) { return "S+A+Y"; }
  if (strcmp("see ", buffer) == 0) { return "MAGIC+S+E"; }
  if (strcmp("she ", buffer) == 0) { return "S+H+E"; }
  if (strcmp("so ", buffer) == 0) { return "S+O"; }
  if (strcmp("some ", buffer) == 0) { return "S+M+E"; }
  if (strcmp("state ", buffer) == 0) { return "S+T+E"; }
  if (strcmp("such ", buffer) == 0) { return "S+U+H"; }
  if (strcmp("take ", buffer) == 0) { return "T+K+E"; }
  if (strcmp("than ", buffer) == 0) { return "T+H+N"; }
  if (strcmp("that ", buffer) == 0) { return "T+H+A"; }
  if (strcmp("the ", buffer) == 0) { return "T+H"; }
  if (strcmp("their ", buffer) == 0) { return "MAGIC+T+R"; }
  if (strcmp("them ", buffer) == 0) { return "T+H+E"; }
  if (strcmp("then ", buffer) == 0) { return "MAGIC+T+N"; }
  if (strcmp("there ", buffer) == 0) { return "T+H+R"; }
  if (strcmp("these ", buffer) == 0) { return "MAGIC+T+S"; }
  if (strcmp("they ", buffer) == 0) { return "T+E+Y"; }
  if (strcmp("think ", buffer) == 0) { return "T+I+K"; }
  if (strcmp("this ", buffer) == 0) { return "T+H+S"; }
  if (strcmp("those ", buffer) == 0) { return "T+O+S"; }
  if (strcmp("time ", buffer) == 0) { return "T+I+E"; }
  if (strcmp("to ", buffer) == 0) { return "T+O"; }
  if (strcmp("up ", buffer) == 0) { return "U+P"; }
  if (strcmp("use ", buffer) == 0) { return "MAGIC+U+S"; }
  if (strcmp("way ", buffer) == 0) { return "W+A+Y"; }
  if (strcmp("we ", buffer) == 0) { return "W+E"; }
  if (strcmp("what ", buffer) == 0) { return "W+H+A"; }
  if (strcmp("when ", buffer) == 0) { return "W+H+N"; }
  if (strcmp("where ", buffer) == 0) { return "W+H+R"; }
  if (strcmp("which ", buffer) == 0) { return "W+H+I"; }
  if (strcmp("who ", buffer) == 0) { return "W+H+O"; }
  if (strcmp("why ", buffer) == 0) { return "MAGIC+W+Y"; }
  if (strcmp("will ", buffer) == 0) { return "W+I+L"; }
  if (strcmp("with ", buffer) == 0) { return "W+T+H"; }
  if (strcmp("work ", buffer) == 0) { return "W+R+K"; }
  if (strcmp("would ", buffer) == 0) { return "W+L+D"; }
  if (strcmp("year ", buffer) == 0) { return "Y+E+A"; }
  if (strcmp("you ", buffer) == 0) { return "Y+O+U"; }
  return NULL;
}
