import React from 'react';

const HeaderItem = ({ text, targetSection }) => {
  const onClick = () => { window.location.href = `#${targetSection}`; };
  return (
    <div className="navigation-item" onClick={onClick} role="button" tabIndex="0" onKeyDown={onClick}>
      {text}
    </div>
  );
};

const Header = () => (
  <div className="header">
    <>
      <HeaderItem text="caleballen.dev" targetSection="" />
      <div className="navigation-section">
        <HeaderItem text="dab" targetSection="dab" />
        <HeaderItem text="dab2" targetSection="dab" />
      </div>
    </>
  </div>
);

export default Header;
