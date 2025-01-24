local M={}

local whichkey = require "which-key"


function M.setup()
  local keymap= 
  {
    { "<leader>so", "<cmd>lua require'Luogu-On-Neovim'.solution()<cr>", desc = "Solution", mode = "n" },
    { "<leader>ss", "<cmd>lua require'Luogu-On-Neovim'.submit()<cr>", desc = "Submit", mode = "n" },
    { "<leader>sp", "<cmd>lua require'Luogu-On-Neovim'.problem()<cr>", desc = "Problem", mode = "n" },
    { "<leader>sl", "<cmd>lua require'Luogu-On-Neovim'.login()<cr>", desc = "Login", mode = "n" },
    { "<leader>si", "<cmd>lua require'Luogu-On-Neovim'.install()<cr>", desc = "Install", mode = "n" },
  }
  whichkey.add(keymap)
end

function M.login()
  vim.api.nvim_command(":te ~/.config/luogu-cli/LuoguCLI login")
end

function M.install()
  vim.api.nvim_command(":te  rm -rf ~/.config/luogu-cli && mkdir ~/.config/luogu-cli && cd /tmp && rm -rf Luogu-On-Neovim && git clone https://github.com/Bot-wxt1221/Luogu-On-Neovim.git && cd Luogu-On-Neovim && cd luogu-cli && mkdir out && cd out && cmake .. && make && cp LuoguCLI ~/.config/luogu-cli/LuoguCLI && touch ~/.config/luogu-cli/a.txt")
end

function M.submit()
  local proble=vim.ui.input({prompt='[Luogu-CLI]Enter Problem Code:',default=vim.fn.expand('%:t:r')},function(input)   vim.api.nvim_command("!~/.config/luogu-cli/LuoguCLI submit "..input.." %") end);
end

function M.solution()
    local proble=vim.ui.input({prompt='[Luogu-CLI]Enter Problem Code:',default=vim.fn.expand('%:t:r')},function(input)   vim.api.nvim_command("!~/.config/luogu-cli/LuoguCLI  solution "..input) end);
end

function M.problem()
    local proble=vim.ui.input({prompt='[Luogu-CLI]Enter Problem Code:',default=vim.fn.expand('%:t:r')},function(input)   vim.api.nvim_command("!~/.config/luogu-cli/LuoguCLI  problem "..input) end);
end



return M
