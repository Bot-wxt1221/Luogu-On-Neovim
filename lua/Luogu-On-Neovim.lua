local M={}

local whichkey = require "which-key"


function M.setup()
  local keymap={
    s = {
      name = "Luogu",
      s = { "<cmd>lua require'Luogu-On-Neovim'.submit()<cr>", "Submit current problem" },
      o = { "<cmd>lua require'Luogu-On-Neovim'.solution()<cr>", "Read solution" },
      p = { "<cmd>lua require'Luogu-On-Neovim'.problem()<cr>", "View problem" },
      l = { "<cmd>lua require'Luogu-On-Neovim'.login()<cr>", "login" },
      i = {"<cmd> lua require 'Luogu-On-Neovim'.install()<cr>","install"},
    },
  }
  local opts = {
    mode = "n",
    prefix = "<leader>",
    buffer = nil,
    silent = true,
    noremap = true,
    nowait = false,
  }
  whichkey.register(keymap, opts)
end

function M.login()
  vim.api.nvim_command(":te ~/.config/luogu-cli/LuoguCLI login")
end

function M.install()
  vim.api.nvim_command(":te  rm -rf ~/.config/luogu-cli && mkdir ~/.config/luogu-cli && cd /tmp && rm -rf Luogu-On-Neovim && git clone https://github.com/Bot-wxt1221/Luogu-On-Neovim.git && cd Luogu-On-Neovim && cd luogu-cli && mkdir out && cd out && cmake .. && make && cp LuoguCLI ~/.config/luogu-cli/LuoguCLI && touch ~/.config/luogu-cli/a.txt")
end

function M.submit()
  local proble=vim.ui.input({prompt='[Luogu-CLI]Enter Problem Code:'},function(input)   vim.api.nvim_command("!~/.config/luogu-cli/LuoguCLI submit "..input.." %") end);
end

return M
