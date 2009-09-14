#!/usr/bin/lua
-- A filter script to translate xml data, it affects all coordinates in the
-- form of <tag x=".." y=".." />.
if #arg < 2 then
    print("Usage: " .. arg[0] .. " x y")
    os.exit(1)
end

-- Translation table.
translation = {
    x = arg[1],
    y = arg[2]
}

-- Translate filter.
function translate(word)
    local _, _, coordinate, value = string.find(word, "([xy])=\"([^\"]+)\"")
    value = value + translation[coordinate]
    return coordinate .. "=\"" .. value .. "\""
end

for line in io.lines() do
    if string.find(line, "position") or string.find(line, "point") then
        line = string.gsub(line, "[xy]=\"[^\"]+\"", translate)
    end

    print(line)
end
