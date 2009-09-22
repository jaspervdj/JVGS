jlib = {
    randomItem = function(list)
        return list[math.random(1, #list)]
    end,

    map = function(list, f)
        local result = {}
        for i, v in ipairs(list) do result[i] = f(v) end
        return result
    end
}
