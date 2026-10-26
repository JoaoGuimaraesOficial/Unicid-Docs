RESUMO REQUESITOS FRONT-END:



**4 Página:**

&#x09;  - Início — index.html - Nome da ONG; causa defendida; apresentação breve; imagem ou destaque visual pertinente; chamada para conhecer projetos ou participar.

&#x09;  - Sobre — sobre.html - Contexto ou história; missão; público atendido; objetivos e informações institucionais coerentes.

&#x09;  - Projetos — projetos.html - No mínimo três iniciativas com nome, descrição, imagem ou elemento visual e indicação de contribuição da comunidade.

&#x09;  - Contato — contato.html - Formulário com nome, e-mail, assunto e mensagem; orientações de voluntariado/participação; aviso de envio apenas simulado.



**\*\*\* HTML5 — estrutura, semântica e navegação \*\*\***

• Documento completo com <!DOCTYPE html>, lang="pt-BR", UTF-8, <title> apropriado e meta viewport.

• Uso coerente de header, nav, main, footer e de section/article quando houver sentido semântico.

• Títulos em hierarquia lógica, parágrafos, listas e links com textos compreensíveis.

• Menu funcional nas quatro páginas; todos os links e caminhos de arquivos devem funcionar.

• Imagens pertinentes, com alt adequado; créditos e fontes informados quando necessários.

• Formulário com label associado a cada campo; nome, e-mail, assunto e mensagem; tipo email e atributos HTML adequados como required/minlength.



**\*\*\* CSS3 — identidade visual e organização \*\*\***

• Folha de estilos externa, compartilhada e organizada com seletores e classes. Nome de arquivo livre, desde que os caminhos funcionem.

• Cores, fontes, legibilidade, contrastes, espaçamentos, margens, bordas, padding, line-height e box-sizing.

• Pelo menos uma seção organizada com display: flex, com propriedades de alinhamento ou espaçamento quando apropriadas.

• Responsividade real com larguras flexíveis, imagens adaptáveis e pelo menos uma regra @media que modifique o layout.

• Controles e links identificáveis e operáveis por teclado, sem perda de legibilidade.



**A equipe deve demonstrar o site funcionando em largura próxima de 390 px (celular) e 1280 px (desktop), sem**

**sobreposição de textos, rolagem horizontal indevida ou perda de acesso a menus e botões.**



**JavaScript: exatamente duas funcionalidades**

O escopo obrigatório foi reduzido para estar alinhado às quatro aulas de JavaScript.



**FUNCIONALIDADE 1 — FORMULÁRIO VALIDADO (obrigatória)**

Na página de contato, a equipe deverá:

• Registrar o evento submit do formulário com addEventListener() e impedir o envio/recarregamento padrão com preventDefault().

• Ler os valores dos quatro campos usando value e tratar espaços desnecessários, por exemplo, com trim().

• Verificar nome com no mínimo 3 caracteres; e-mail preenchido e em formato básico válido; assunto não vazio; mensagem com no mínimo 10 caracteres (após trim).

• Apresentar mensagem visível no próprio HTML quando houver erro e mensagem de confirmação quando todos os dados forem válidos.

• Informar claramente que a confirmação é simulada: não houve envio real de e-mail ou coleta de dados.



**FUNCIONALIDADE 2 — UMA INTERAÇÃO ADICIONAL (obrigatória)**

A equipe deverá implementar uma interação além do formulário, como mostrar/ocultar informações da ONG, abrir/fechar

respostas de perguntas frequentes ou atualizar uma mensagem ao clicar. Ela deve:

• Possuir controle HTML identificável, preferencialmente <button>, com ação registrada em JavaScript via addEventListener("click", ...).

• Executar uma função JavaScript e alterar o estado visível de algum elemento da página usando DOM.

• Exibir comportamento coerente e repetível: por exemplo, um clique mostra a informação e outro clique a oculta.



**OBRIGATÓRIO** - Quatro páginas HTML; requisitos semânticos e de CSS da página anterior; uma interação JS adicional; um formulário com validação e resposta visível.

&#x09;    - JavaScript em arquivo externo; registro dos dois eventos com addEventListener(); separação de código HTML, CSS e JS; demonstração real no navegador.



**PERMITIDO, NÃO OBRIGATÓRIO** - Usar style.display, classList ou outra abordagem correta para controlar visibilidade. Não há ponto específico por escolher um desses métodos.

&#x09;		   - Escrever type="button" em botão fora de formulário. O atributo é recomendável em situações apropriadas, mas sua ausência fora de form não ocasiona desconto.

&#x09;		   - Usar getElementById() ou querySelector() para selecionar elementos, desde que o código funcione e seja compreensível.



**NÃO EXIGIDO** - Arrays, laços (for, while, for...of), métodos como map/filter, programação orientada a objetos, JSON, localStorage, fetch, APIs externas, async/await e expressões regulares.

&#x09;    - console.log(), utilização do Console como demonstração, publicação em GitHub Pages, backend, banco de dados, envio de e-mails, login, pagamentos ou integração com serviços reais.



**01** — Planejar 

Escolher a ONG, definir público e causa, reunir fontes e esboçar as quatro páginas. Mapa do site e textos planejados.



**02** — HTML 

Construir páginas, semântica, links, três projetos e formulário com labels. Quatro arquivos HTML navegáveis.



**03** — CSS 

Criar identidade visual, organização com Flexbox e adaptação a telas pequenas. Páginas legíveis no celular e desktop.



**04** — JS 

Implementar formulário validado e uma interação adicional, com retorno visível. Duas funcionalidades testadas.



**05** — Revisar 

Corrigir problemas, organizar pastas, creditar materiais e preparar demonstração. ZIP final e README.



**Entregáveis obrigatórios**

• Arquivo .zip com os quatro HTML, CSS, JavaScript, imagens e demais recursos utilizados.

• README.md ou README.txt com ONG, integrantes, objetivo, páginas, duas funcionalidades JS, instruções de execução e fontes/créditos.

• Demonstração no navegador: navegar pelas páginas; mostrar a interação adicional; testar formulário com erro e acerto; exibir a adaptação para celular.



**Exemplo de estrutura de arquivos**



**PASTA DO PROJETO ARQUIVOS**

ONG\_Exemplo/ index.html · sobre.html · projetos.html · contato.html

ONG\_Exemplo/css/ estilos.css

ONG\_Exemplo/js/ script.js e/ou formulario.js

ONG\_Exemplo/img/ imagens utilizadas no site

ONG\_Exemplo/ README.md









