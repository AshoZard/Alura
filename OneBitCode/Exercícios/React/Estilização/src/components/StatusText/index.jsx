export default () => {
  const status = true;

  return (
    <h2 style={{ color: status ? "#00ff9f" : "#f64648" }}>
      Current status: {status ? "ON" : "OFF"}
    </h2>
  );
};

//esse tipo de "dinamismo" só é possível assim, em arquivo separado não existe a variável.
