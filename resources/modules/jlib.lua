module("jlib", package.seeall)

function randomItem(list)
    return list[math.random(1, #list)]
end

function map(list, f)
    local result = {}
    for i, v in ipairs(list) do result[i] = f(v) end
    return result
end
